#include "TMTapeFlattener.h"
#include "DChar.h"

TMTapeFlattener::TMTapeFlattener()
{
}


TMTapeFlattener::~TMTapeFlattener()
{
}

DString* TMTapeFlattener::Flatten(std::string input, int tapes, int iterations)
{
   return Flatten(DString(input), tapes, iterations);
}

DString* TMTapeFlattener::Flatten(DString input, int tapes, int iterations)
{
   DString dszOutput;
   for (int i = 1; i <= iterations; i++)
   {
      DString szOutput;
      std::vector<std::string> decorators = { "*" };
      szOutput.operator+(DChar("#", {}));

      for (int t = 0; t < input.size(); t++)
      {
         std::string baseChar = input.substr(t, 1).getString().substr(0, 1);
         if (baseChar == "#" ||
            baseChar == "R" ||
            baseChar == "$")
         {
            int k = 0;
            std::string charNow = input.substr(t, 1).getString();
            while (k < charNow.size() && charNow[k] != '[')
            {
               k++;
            }
            baseChar += std::string(k, '*');
            (input).set(t, DChar(baseChar, {}));
         }
      }
      decorators = { std::to_string(i) };
      szOutput.operator+(DChar((input)[0], decorators) );

      for (int t = 1; t < input.size(); t++)
      {
            szOutput.operator+(DChar((input)[t], {}));
      }

      for (int t = 1; t < tapes; t++)
      {
         szOutput.operator+(DChar("#" + std::string(i-1,'*'),{}));
         decorators = { std::to_string(i) };
         szOutput.operator+(DChar("_", decorators));
      }

      szOutput.operator+(DChar("#", {}));
      szOutput.operator+(DChar("$", {}));
      input = szOutput;
      dszOutput = szOutput;
      tapes = 1;
   }

   return new DString(dszOutput);
}