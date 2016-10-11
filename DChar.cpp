#include <iostream>
#include "DChar.h"



DChar::DChar(std::string base, int i = 0)
{
    m_cBase = base;
	m_vecHeads = std::vector<std::string>();
}

DChar::DChar(std::string base, std::vector<std::string> is)
{
	m_cBase = base;
	m_vecHeads = is;
}

DChar::DChar(DChar base, std::vector<std::string> is)
{
   m_cBase = base.getBase();
   m_vecHeads = base.getHeaders();
   for (int i = 0; i < is.size(); i++)
   {
      m_vecHeads.push_back(is[i]);
   }
}

DChar::~DChar()
{
}

std::string DChar::getBase() const
{
    return m_cBase;
}

bool DChar::operator==(const DChar& other) const
{
	bool headSame = true;
	if ((headSame &= (m_cBase == other.getBase())) &&
		(headSame &= (other.getDecorations() == getDecorations())))
	{
		for (int i = 0; i < m_vecHeads.size(); i++)
		{
			headSame &= m_vecHeads[i] == other.m_vecHeads[i];
		}
	}
	
    return (headSame);
}

int DChar::getDecorations() const
{
    return m_vecHeads.size();
}

std::vector < std::string> DChar::getHeaders() const
{
	return m_vecHeads;
}

void DChar::setDecorations(int i)
{
    m_iDecorations = i;
}

std::string DChar::getString() const
{
	std::string heads = "";
	if (m_vecHeads.size() > 0)
	{
		heads = "[";
		for (int i = 0; i < m_vecHeads.size(); i++)
		{
			heads += m_vecHeads[i];
			if (i != m_vecHeads.size() - 1)
			{
				heads += ",";
			}
		}

		heads += "]";
	}
	
    //return std::string(this->getDecorations(), '.') + m_cBase;
	return heads + m_cBase;
}