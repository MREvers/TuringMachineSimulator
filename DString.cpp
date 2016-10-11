#include "DString.h"



DString::DString()
{
}

DString::DString(std::string base)
{
    for (int i = 0; i < base.size(); i++)
    {
        *this += DChar((std::string(1, base[i])), 0);
    }
}

DString::~DString()
{
}

DString& DString::operator+=(DChar other)
{
    m_szString.push_back(new DChar(other));
    return *this;
}

DString& DString::operator+(DChar other)
{
	m_szString.push_back((new DChar(other)));
	return *this;
}

DString& DString::operator+(std::string other)
{
    for (int i = 0; i < other.size(); i++)
    {
        DChar* newChar = new DChar(std::string(1, other[i]), 0);
        *this += (*newChar);
    }
    return *this;
}

DString& DString::operator+(DString other)
{
	for (int i = 0; i < other.size(); i++)
	{
		DChar* newChar = new DChar((other)[i].getBase(), (other)[i].getHeaders());
		*this += *(newChar);
	}
	return *this;
}

int DString::size() const
{
    return m_szString.size();
}

std::string DString::getString() const
{
    std::string szRetVal;
    for (int i = 0; i < size(); i++)
    {
        szRetVal += m_szString[i]->getString();
    }
    return szRetVal;
}

DString DString::substr(int iStart, int iLength) const
{
    DString lstRetVal;
    for (int i = iStart; (i < size() && (i - iStart) < iLength); i++)
    {
        lstRetVal += *m_szString[i];
    }
    return lstRetVal;
}

const DChar& DString::operator[](int i) const
{
    return *m_szString[i];
}

void DString::set(int i, DChar other)
{
   delete m_szString[i];
   m_szString[i] = new DChar(other);
}