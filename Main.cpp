#include <iostream>
#include <string>
#include <thread>
#include "TMLoader.h"
#include "TuringMachine.h"

// Todo: Organize TFs into a tree structure
// Todo: Make it sort better.
// Todo: Make an input helper that takes an input on n tapes and flattens it.
// Redo: Fix the DCHar memory leak.
// Redo: Fix the DString memory leak.
void main()
{
    TMLoader tml;
    std::vector<TransitionFunction*> tfs;
	std::string startState;
	std::vector<std::string> endStates;
	/*
    if (!tml.loadTFFile("Input2.txt", tfs))
    {
        return;
    }
   
    TuringMachine tmTest(3);
    tmTest.initialize("q0", "q5", 15);
    tmTest.setInput("101#1110");
	*/
	if (!tml.loadTFFile("Test3.txt", tfs, startState, endStates))
	{
		return;
	}

	TuringMachine tmTest(1);
	tmTest.initialize(startState, endStates[0], 15);
	/*
	DString input("#");
	input = (input + (new DChar('1', 1)) + "1|1#" + (new DChar('_', 1)) + "#" + (new DChar('_', 1)) + "#$");
	*/

	DString input("#");
	input = (input + (new DChar('1', std::vector < std::string> { "2" })) +
		+ (new DChar('1', std::vector < std::string> { "1" })) + "1#" + (new DChar('_', std::vector < std::string> { "1" })) + "#$");
	tmTest.setInput(input);
    

    for (int i = 0; i < tfs.size(); i++)
    {
        tmTest.includeTransitionFunction(tfs[i]);
    }
    std::vector<std::string> machineOutput;
	int hi = 0;
    do
    {
       
		if (hi % 1 == 0)
		{
			machineOutput = tmTest.getDrawState();
			system("cls");
			for (int i = 0; i < 2; i++)
			{
				std::cout << machineOutput[i] << std::endl;
			}
			std::cout << tmTest.getState() << std::endl;
			std::cout << hi << " steps" << std::endl;
		}
		hi++;
        _sleep(150);
    } while (tmTest.stepForward());
    system("cls");
    machineOutput = tmTest.getDrawState();
    for (int i = 0; i < 2; i++)
    {
        std::cout << machineOutput[i] << std::endl;
    }
    std::cout << tmTest.getLastStepResult() << std::endl;
	std::cout << tmTest.getState() << std::endl;
	std::cout << hi << " steps" << std::endl;

	std::cin.get();
}