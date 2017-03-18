#pragma once
#include<vector>
#include<string>
#include "DChar.h"

class DString
{
public:
   DString();
   DString(const DString& aoBase);
   DString(std::string base);
   ~DString();

   DString& operator+(std::string other);
   DString& operator+(DString other);
   DString& operator+(DChar other);
   DString& operator+=(DChar other);
   const DChar& operator[](int i) const;


   int size() const;

   DString substr(int iStart, int iLength) const;
   void set(int i, DChar other);

   std::string getString() const;

private:
   std::vector<DChar> m_szString;
};

