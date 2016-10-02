#pragma once
#include <vector>
#include "MachineTape.h"
#include "DChar.h"

class TransitionFunction
{
public:
    TransitionFunction();
    ~TransitionFunction();

    void define(int iNumTapes);
    bool initialize(
        std::string domainState,
        std::vector<DChar*> domainHeadValues,
        std::string rangeState,
        std::vector<DChar*> rangeHeadValues,
        std::vector<TRANSITION> rangeHeadMoves);

    int getTapeCount() const;
    std::string getDomainState() const;
    std::string getRangeState() const;
    DChar* getDomainHeadValue(int iTapeNum) const;
    DChar* getRangeHeadValue(int iTapeNum) const;
    TRANSITION getRangeHeadMove(int iTapeNum) const;

private:
    int m_iNumTapes;
    std::string m_DomainState;
    std::string m_RangeState;
    std::vector<DChar*> m_cDomainValues;
    std::vector<DChar*> m_cRangeValues;
    std::vector<TRANSITION> m_RangeHeadMove;
};

