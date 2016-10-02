#include "TransitionFunction.h"



TransitionFunction::TransitionFunction()
{
    m_iNumTapes = 0;
}


TransitionFunction::~TransitionFunction()
{
}

int TransitionFunction::getTapeCount() const
{
    return m_iNumTapes;
}

void TransitionFunction::define(int iNumTapes)
{
    m_iNumTapes = iNumTapes;
}

bool TransitionFunction::initialize(std::string domainState,
    std::vector<DChar*> domainHeadValues,
    std::string rangeState,
    std::vector<DChar*> rangeHeadValues,
    std::vector<TRANSITION> rangeHeadMoves)
{
    bool bRetVal = true;

    m_DomainState = domainState;

    if (bRetVal &= (domainHeadValues.size() == m_iNumTapes))
    {
        m_cDomainValues = domainHeadValues;
        
    }

    m_RangeState = rangeState;

    if (bRetVal &= (rangeHeadValues.size() == m_iNumTapes))
    {
        m_cRangeValues = rangeHeadValues;
    }

    if (bRetVal &= (rangeHeadMoves.size() == m_iNumTapes))
    {
        m_RangeHeadMove = rangeHeadMoves;
    }

    return bRetVal;
}

DChar* TransitionFunction::getRangeHeadValue(int iTapeNum) const
{
    return m_cRangeValues[iTapeNum];
}

DChar* TransitionFunction::getDomainHeadValue(int iTapeNum) const
{
    return m_cDomainValues[iTapeNum];
}

TRANSITION TransitionFunction::getRangeHeadMove(int iTapeNum) const
{
    return m_RangeHeadMove[iTapeNum];
}

std::string TransitionFunction::getRangeState() const
{
    return m_RangeState;
}

std::string TransitionFunction::getDomainState() const
{
    return m_DomainState;
}