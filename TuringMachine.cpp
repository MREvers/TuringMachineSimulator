#include <iostream>
#include "TuringMachine.h"



TuringMachine::TuringMachine(int iNumTapes)
{
    m_iNumTapes = iNumTapes;
    
    for (int i = 0; i < iNumTapes; i++)
    {
        m_lstTapes.push_back(new MachineTape());
    }
}


TuringMachine::~TuringMachine()
{
}

void TuringMachine::initialize(std::string szStartState, std::string szEndState, int iHeadPos)
{
    m_szStartState = szStartState;
    m_szEndStates.push_back(szEndState);

    for (int i = 0; i < m_iNumTapes; i++)
    {
        m_lstTapes[i]->setHeadPosition(iHeadPos);
    }

    m_szCurrentState = szStartState;
}

void TuringMachine::includeEndState(std::string szEndState)
{
    m_szEndStates.push_back(szEndState);
}

bool TuringMachine::includeTransitionFunction(TransitionFunction *tf)
{
    bool bRetVal;
    if (bRetVal = (tf->getTapeCount() == m_iNumTapes))
    {
        m_lstTransitionSet.push_back((tf));
    }
    return bRetVal;
}

std::string TuringMachine::getLastStepResult()const
{
    std::string szRetVal;
    if (m_LastStepResult == SUCCESS)
    {
        szRetVal = "OK";
    }
    else if (m_LastStepResult == ACCEPT)
    {
        szRetVal = "ACCEPT";
    }
    else
    {
        szRetVal = "REJECT";
    }
    return szRetVal;
}

std::vector<std::string> TuringMachine::getDrawState() const
{
    std::vector < std::string> szRetVal;
    for (int i = 0; i != m_iNumTapes; i++)
    {
        std::vector<std::string> szTapeState = m_lstTapes[i]->getDrawState(true);
        szRetVal.push_back(szTapeState[0]);
        szRetVal.push_back(szTapeState[1]);
    }

    return szRetVal;
}

std::string TuringMachine::getState() const
{
	return m_szCurrentState;
}

void TuringMachine::setInput(std::string szInput) 
{
    m_lstTapes[0]->setState(szInput);
}

void TuringMachine::setInput(DString szInput)
{
	m_lstTapes[0]->setState(szInput);
}

// Returns true if the machine can continue to step forward.
bool TuringMachine::stepForward()
{
    bool bRetVal = true;
    
    bool found = false;
    int foundTF;
    // Find if there is an applicable transition function
    for (int i = 0; i != m_lstTransitionSet.size(); i++)
    {
        found = (m_lstTransitionSet[i]->getDomainState() == m_szCurrentState);

		if (found)
		{
			for (int t = 0; t != m_iNumTapes && found; t++)
			{
				found &= *(m_lstTransitionSet[i]->getDomainHeadValue(t)) == m_lstTapes[t]->getState();
			}
		}
        

        if (found)
        {
            foundTF = i;
			std::cout << i << std::endl;
            break;
        }
    }
	
    bRetVal &= found;

    if (bRetVal)
    {
        // Greater than 0 is a successful transition
        bRetVal &= ((m_LastStepResult = performTransitionFunction(m_lstTransitionSet[foundTF])) == SUCCESS);
    }

    return bRetVal;
}

STEPRESULT TuringMachine::performTransitionFunction(TransitionFunction *tf)
{
    STEPRESULT bRetVal;
    bool bSuccess = true;
    for (int i = 0; i < m_iNumTapes; i++)
    {
        bSuccess &= m_lstTapes[i]->performTransform(tf->getRangeHeadMove(i), tf->getRangeHeadValue(i));
    }

    if (bSuccess)
    {
        m_szCurrentState = tf->getRangeState();
        if (checkAccept())
        {
            bRetVal = ACCEPT;
        }
        else
        {
            bRetVal = SUCCESS;
        }
    }
    else
    {
        bRetVal = FAILED;
    }

    return bRetVal;
}

bool TuringMachine::checkAccept() const
{
    bool found = false;
    for (int i = 0; i < m_szEndStates.size(); i++)
    {
        found |= (m_szCurrentState == m_szEndStates[i]);
    }
    return found;
}