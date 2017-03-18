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
   // Load a turing machine
   TMLoader tml;
   std::vector<TransitionFunction*> tfs;
   std::string startState;
   std::vector<std::string> endStates;

   std::string input;
   std::cout << "Please enter a file containing a valid TM: " << std::endl;
   std::cout << "Make sure there is a blank line at EOF: " << std::endl;
   std::getline(std::cin, input);

   std::cout << "Loading..." << std::endl;
   if (!tml.loadTFFile(input, tfs, startState, endStates))
   {
      return;
   }
   system("cls");

   std::cout << "num_tapes is the number of tapes to simulate." << std::endl << std::endl;
   std::cout << "num_tapes_sim is the number of tapes simulated on ONE tape." << std::endl;
   std::cout << "1 If not flattened." << std::endl << std::endl;

   std::cout << "Symbol_Generation is the number of times the TM has been flattened." << std::endl;
   std::cout << "1 If not flattened ever." << std::endl << std::endl;

   std::cout << "Sleep is the delay between transition functions." << std::endl << std::endl;
   std::cout << "input is the string input." << std::endl;
   std::cout << "Enter input: <num_tapes>, <num_tapes_sim>, <Symbol_Generation>, <sleep>; <input>" << std::endl;
   std::getline(std::cin, input);
   while (input != "quit")
   {
      std::vector<std::string> splitInput = TMLoader::splitString(input, ';');
      if (splitInput.size() > 1)
      {
         std::vector<std::string> splitArguments = TMLoader::splitString(input, ',');
         // # of tapes
         // flatten iterations
         if (splitArguments.size() == 4)
         {
            int tapes = std::stoi(splitArguments[0]);
            int pre_flat_tapes = std::stoi(splitArguments[1]);
            int iters = std::stoi(splitArguments[2]);
            int sleep = std::stoi(splitArguments[3]);

            // Modify the input to the correct "Generation"
            TMTapeFlattener tmf;
            DString dszInput;
            if (iters > 0)
            {
               dszInput = tmf.Flatten(trim(splitInput[1]), pre_flat_tapes, iters);
            }
            else
            {
               dszInput = DString(trim(splitInput[1]));
            }

            TuringMachine tm(tapes);
            tm.initialize(startState, endStates[0], 15);
            tm.setInput(dszInput);

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
                  for (int i = 0; i < machineOutput.size(); i++)
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
            for (int i = 0; i <  machineOutput.size(); i++)
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
         std::cout << "Enter input: <num_tapes>, <num_tapes_sim>, <Symbol_Generation>, <sleep>; <input>" << std::endl;
         std::getline(std::cin, input);
      }
   }
}