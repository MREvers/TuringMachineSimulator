#pragma once
#include <vector>
#include "TransitionFunction.h"

class TMLoader
{
public:
    TMLoader();
    ~TMLoader();

    bool loadTFFile(std::string fileName, std::vector<TransitionFunction*> &output, std::string &startState, std::vector<std::string> &endStates);

	std::vector<std::string> parseHeads(std::string szInput) const;
	std::string parseBase(std::string szInput) const;
   static std::vector<std::string> splitString(const std::string szInString, char cSplitChar);

   TRANSITION convertCharToTranstion(char cMap) const;
};

