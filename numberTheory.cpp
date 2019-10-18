
# include "numberTheory.hpp"
# include <iostream>
# include <string>
# include <cmath>
# include <iomanip>
# include <cstdlib>
# include <vector>
# include <sstream>
# include <algorithm>

using namespace std;


ReallyLongInt numberTheory:: extendedEuclid(const ReallyLongInt& a, const ReallyLongInt& b,  ReallyLongInt& x,  ReallyLongInt& y)
{

 
  ReallyLongInt ax = 0;
  ReallyLongInt ay = 0;
  
  if (b.equal(0)) {
    
    x = 1;

    y = 0;

    return a;
  }

  else {

    ReallyLongInt d;
    numberTheory n;
    
    d = extendedEuclid(b, a%b, x, y);
       
   

    ax = y;
    ay = x - y * (a / b);
    
      
    x = ax;
    y = ay;

    return d;
  }
}
