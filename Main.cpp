#include <iostream>
#include <string>
#include <thread>
#include "TMLoader.h"
#include "TuringMachine.h"
#include "TMTapeFlattener.h"
#include "TMSimulator.h"

// Todo: Organize TFs into a tree structure
// Todo: Make it sort better.
// Todo: Make an input helper that takes an input on n tapes and flattens it.
// Redo: Fix the DCHar memory leak.
// Redo: Fix the DString memory leak.
void main()
{
   TMSimulator tms;
   tms.sim_loop();
   std::cin.get();
}