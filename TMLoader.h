#pragma once
#include <vector>
#include "TransitionFunction.h"

class TMLoader
{
public:
   TMLoader();
   ~TMLoader();

   /* loadTFFile
   *  Expects a plain-text file where the first three lines are
   *  name: <string_name>
   *  init: <state>
   *  accept: <state>
   *
   *  Then Transition functions 1 per 2 lines
   *  <Domain_State>, [<Domain_Input>, ...]
   *  <Range_State>, [<Range_Output>, ...], [<Head_Moves>, ...]
   */
   bool loadTFFile(std::string fileName, std::vector<TransitionFunction*> &output, std::string &startState, std::vector<std::string> &endStates);

   std::vector<std::string> parseHeads(std::string szInput) const;
   std::string parseBase(std::string szInput) const;
   static std::vector<std::string> splitString(const std::string szInString, char cSplitChar);

   TRANSITION convertCharToTranstion(char cMap) const;
};

