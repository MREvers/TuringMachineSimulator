#include <iostream>
#include "DChar.h"



DChar::DChar(char base, int i = 0)
{
    m_cBase = base;
    m_iDecorations = i;
}


DChar::~DChar()
{
}

char DChar::getBase() const
{
    return m_cBase;
}

bool DChar::operator==(const DChar& other) const
{
    return (m_cBase == other.getBase() && m_iDecorations == other.getDecorations());
}

int DChar::getDecorations() const
{
    return m_iDecorations;
}

void DChar::setDecorations(int i)
{
    m_iDecorations = i;
}

std::string DChar::getString() const
{
    return std::string(m_iDecorations, '.') + m_cBase;
}