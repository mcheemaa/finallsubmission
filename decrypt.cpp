
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
  
  if (argc != 4) {
    return 1;
  }

  ifstream inFile;
  ifstream inFile2;
  ofstream outfile;

  inFile.open(argv[1]);
  outfile.open(argv[3]);
  
  if (!inFile) {
    exit(1); // terminate with error
  }

  string word;

  string e1 ;
  string e2;

  int i = 0;
  
  while (inFile >> word) 
    {
      
      if (i == 0) {
	e1 = word;
      }
      if (i == 1) {
	e2 = word;
      }
      i++;
    }
  ReallyLongInt d(stoll(e1));
  ReallyLongInt n(stoll(e2));


  //cout << "d " << d.toString()  << "\n";
  //cout << "n " << n.toString()  << "\n";
  

  inFile.close();
  inFile2.open(argv[2]);

  if (!inFile2) {
    
    //cout << "No Second File Provided " << "\n";
    exit(1); // terminate with error
  }
  int asVal;
  ReallyLongInt x;
  char chara;
  
  while (inFile2 >> chara) {

    //cout << "goes into while loop " << "\n";
    
    asVal = (int)chara;

    ReallyLongInt y(asVal);

    //cout << "y value is " << y.toString()   << "\n";

    //cout << "checking ecponent " << (y.exp(d)).toString()  << "\n";

    x = (y.exp(d)) % (n);

    //cout << "goes past % " << "\n";

    //cout << "checking ecponent " << (y.exp(d)).toString()  << "\n";

    long long in = stoll(y.toString(), nullptr,10);
    //long long in = 100;

    //cout << "asc2 after " << in  << "\n";

    char fin = (char)in;

    //cout << "characters after " << fin  << "\n";

    outfile << fin;
    
  }

  inFile2.close();
  outfile.close();
  
  ReallyLongInt z;
  
  
}
