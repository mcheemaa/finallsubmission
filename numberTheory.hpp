
#ifndef NUMBERTHEORY_h
#define NUMBERTHEORY_h


# include "ReallyLongInt.hpp"
# include <iostream>
# include <string>
# include <cmath>
# include <iomanip>
# include <cstdlib>
# include <vector>
# include <sstream>

using namespace std;


class numberTheory
{
  
public:
  
  ReallyLongInt extendedEuclid(const ReallyLongInt& a, const ReallyLongInt& b,  ReallyLongInt& x, ReallyLongInt& y);
  
  
  
};

#endif

