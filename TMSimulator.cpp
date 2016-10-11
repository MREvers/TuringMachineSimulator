#include "TMSimulator.h"
#include "TMLoader.h"
#include "TMTapeFlattener.h"
#include "TuringMachine.h"
#include "StringExtensions.h"
#include <string>
#include <vector>
#include <iostream>


TMSimulator::TMSimulator()
{
}


TMSimulator::~TMSimulator()
{
}

void TMSimulator::sim_loop()
{
   TMLoader tml;
   std::vector<TransitionFunction*> tfs;
   std::string startState;
   std::vector<std::string> endStates;

   std::cout << "Loading..." << std::endl;
   if (!tml.loadTFFile("CopyFlat2.txt", tfs, startState, endStates))
   {
      return;
   }
   
   std::string input;
   std::cout << "Enter input: <num_tapes>, <iters>, <sleep>; <input>" << std::endl;
   std::getline(std::cin, input);
   while (input != "quit")
   {
      std::vector<std::string> splitInput = TMLoader::splitString(input, ';');
      if (splitInput.size() > 1)
      {
         std::vector<std::string> splitArguments = TMLoader::splitString(input, ',');
         // # of tapes
         // flatten iterations
         if (splitArguments.size() == 3)
         {
            int tapes = std::stoi(splitArguments[0]);
            int iters = std::stoi(splitArguments[1]);
            int sleep = std::stoi(splitArguments[2]);

            TMTapeFlattener tmf;
            DString* dszInput = tmf.Flatten(trim(splitInput[1]), tapes, iters);
            
            TuringMachine tm(1);
            tm.initialize(startState, endStates[0], 15);
            tm.setInput(*dszInput);

            for (int i = 0; i < tfs.size(); i++)
            {
               tm.includeTransitionFunction(tfs[i]);
            }

            std::vector<std::string> machineOutput;
            int hi = 0;
            do
            {

               if (hi % 1 == 0)
               {
                  machineOutput = tm.getDrawState();
                  system("cls");
                  for (int i = 0; i < 2; i++)
                  {
                     std::cout << machineOutput[i] << std::endl;
                  }
                  std::cout << tm.getState() << std::endl;
                  std::cout << hi << " steps" << std::endl;
               }
               hi++;
               _sleep(sleep);
            } while (tm.stepForward());
            system("cls");
            machineOutput = tm.getDrawState();
            for (int i = 0; i < 2; i++)
            {
               std::cout << machineOutput[i] << std::endl;
            }
            std::cout << tm.getLastStepResult() << std::endl;
            std::cout << tm.getState() << std::endl;
            std::cout << hi << " steps" << std::endl;
         }
         else
         {
            input = "quit";
         }

      }
      else
      {
         input = "quit";
      }

      if (input != "quit")
      {
         std::cout << "Enter input: <num_tapes>, <iters>, <sleep>; <input>" << std::endl;
         std::getline(std::cin, input);
      }
   }
}