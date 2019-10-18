
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
    
    //cout << "Please enter all three file names and try again. " << "\n"; 

    return 1;

  }

  ifstream inFile;
  ifstream inFile2;
  ofstream outfile;

  inFile.open(argv[1]);
  outfile.open(argv[3]);
  
  if (!inFile) {
    
    //cout << "No File Opened " << "\n";
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

  //cout << "Value of e " << e1  << "\n";
  
  ReallyLongInt e(stoll(e1));
  ReallyLongInt n(stoll(e2));

  inFile.close();

  inFile2.open(argv[2]);

  if (!inFile2) {
    
    //cout << "No Second File Provided " << "\n";
    exit(1); // terminate with error
  }

  //cout << "Value of e " << e.toString()  << "\n";
  int asVal;

  ReallyLongInt y;

  char chara;
  
  while (inFile2 >> chara) {

    

    //cout << "characters are " << chara  << "\n";
    
    asVal = (int)chara;

    //cout << "asc2 before !!!!! " << asVal  << "\n";
    
    ReallyLongInt x(asVal);

    //cout << "Before Erroe " << (x.exp(e)).toString()  << "\n";
     
    //cout << "n  " << n.toString()  << "\n";
     

    y = (x.exp(e)) % (n);

    //cout << "checking ecponent " << (x.exp(e)).toString()  << "\n";

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
