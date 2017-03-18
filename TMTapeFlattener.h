#pragma once
#include "DString.h"
#include <string>

class TMTapeFlattener
{
public:
   TMTapeFlattener();
   ~TMTapeFlattener();

   DString Flatten(std::string base, int tapes, int iterations);
   DString Flatten(DString base, int tapes, int iterations);

};

