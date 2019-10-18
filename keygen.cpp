
# include <iostream>
# include <string>
#include <fstream>
# include <cmath>
# include <iomanip>
# include <cstdlib>
# include <vector>
# include <sstream>
# include <algorithm>
# include "ReallyLongInt.hpp"
# include "numberTheory.hpp"


using namespace std;

int main(int argc, char** argv) 
{ 
  
  cout << "You have entered " << argc - 1 << " numbers " << "\n"; 

  long long a = stoi(argv[1]) ;
  long long b = stoi(argv[2]) ;

  ReallyLongInt num1 (a);
  ReallyLongInt num2 (b);
  ReallyLongInt n;
  ReallyLongInt t;
  ReallyLongInt e (2);
  ReallyLongInt x;
  ReallyLongInt y;
  ReallyLongInt d;

  ReallyLongInt gcd (0);

  numberTheory test;
  
  
  

  if (!(num1.isPrime() and num2.isPrime())) {
    
    cout << "The numbers you entered are not prime. Try again. " << "\n"; 
    
    return 1;
    
  }
  
  n = num1 * num2;
  
  t = (num1 - 1) * (num2 - 1);
  
  
  
  while ( e.greater(1) and !(e.greater(t)) and !(gcd.equal(1))) {
    
    gcd = test.extendedEuclid(e, t, x, y);

    e = e + 1;
    
  }
  
  if (x.isNeg == false) {
    
    d = x;
    
  }
  
  else {

    d = t + x;
    
    
  }


  //Public(encryption): (e,n);

  ofstream myfile;
  myfile.open ("encrypt.txt");
  myfile << e.toString() + " " + n.toString();
  myfile.close();

  //Public(decryption): (d,n);
  
  ofstream myfile2;
  myfile2.open ("decrypt.txt");
  myfile2 <<  d.toString() + " " + n.toString();
  myfile2.close();
    
  return 0; 

} 


