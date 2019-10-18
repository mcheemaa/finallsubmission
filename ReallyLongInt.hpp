#ifndef REALLYLONGINT_h
#define REALLYLONGINT_h

# include <iostream>
# include <string>
# include <cmath>
# include <iomanip>
# include <cstdlib>
# include <vector>
# include <sstream>

using namespace std;



class ReallyLongInt
{
  
public:

  ReallyLongInt();

  ReallyLongInt(long long num);

  ReallyLongInt(const string& numStr);
 
  ReallyLongInt(const ReallyLongInt& other) ;

  ~ReallyLongInt();

  string toString() const;

  string toStringBinary() const;

  bool equal(const ReallyLongInt& other) const;

  bool greater(const ReallyLongInt& other) const;

  void removeLeadingZeros(void);

  ReallyLongInt& operator=(const ReallyLongInt& other);
  
  ReallyLongInt absAdd(const ReallyLongInt& other) const;

  ReallyLongInt absSub(const ReallyLongInt& other) const;

  ReallyLongInt add(const ReallyLongInt& other) const;

  ReallyLongInt sub(const ReallyLongInt& other) const;

  ReallyLongInt operator-() const;

  ReallyLongInt absMult(const ReallyLongInt& other) const;

  ReallyLongInt mult(const ReallyLongInt& other) const;

  void flipSign();

  void absDiv(const ReallyLongInt& other, ReallyLongInt& quotient,ReallyLongInt& remainder) const;

  void div(const ReallyLongInt& other, ReallyLongInt& quotient,ReallyLongInt& remainder) const;

 
  bool absGreater(const ReallyLongInt& other) const;

  ReallyLongInt exp(ReallyLongInt e ) const;

  bool even (const ReallyLongInt& other) const;

  bool isPrime () const;

  
  bool isNeg;

  
  
  
private:

  vector<bool> *digits;

  unsigned int size;

  
 

  

  void swap(ReallyLongInt other);

 

  
 
};

#endif

ReallyLongInt operator+(const ReallyLongInt& x, const ReallyLongInt& y);

ReallyLongInt operator-(const ReallyLongInt& x,const ReallyLongInt& y);

ReallyLongInt operator*(const ReallyLongInt& x,const ReallyLongInt& y);

ReallyLongInt operator/(const ReallyLongInt& x,const ReallyLongInt& y);

ReallyLongInt operator%(const ReallyLongInt& x,const ReallyLongInt& y);

