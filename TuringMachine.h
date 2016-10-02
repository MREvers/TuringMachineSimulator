#pragma once
#include <vector>
#include "MachineTape.h"
#include "TransitionFunction.h"
#include "DChar.h"
#include "DString.h"

enum STEPRESULT { SUCCESS = 1, FAILED = 0, ACCEPT = 2, REJECT = -1 };

class TuringMachine
{
public:
	TuringMachine(int iNumTapes);
	~TuringMachine();

    void initialize(std::string szStartState, std::string szEndState, int iHeadPos);

    std::vector<std::string> getDrawState() const;

    bool includeTransitionFunction(TransitionFunction* tf);
    void includeEndState(std::string szEndState);

    std::string getLastStepResult() const;
	std::string getState() const;

    void setInput(std::string szInput);
	void setInput(DString szInput);
    bool stepForward();
    STEPRESULT performTransitionFunction(TransitionFunction* tf);

private:
    int m_iNumTapes;
    std::vector<MachineTape*> m_lstTapes;
    STEPRESULT m_LastStepResult;

    std::string m_szStartState;
    std::vector<std::string> m_szEndStates;
    std::vector<DChar*> m_lstInputLibrary;
    std::vector<DChar*> m_lstTapeLibrary;
    std::vector<TransitionFunction*> m_lstTransitionSet;

    std::string m_szCurrentState;

    bool checkAccept() const;
};

