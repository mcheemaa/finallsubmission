
# include "ReallyLongInt.hpp"
# include <iostream>
# include <string>
# include <cmath>
# include <iomanip>
# include <cstdlib>
# include <vector>
# include <sstream>
# include <algorithm>

using namespace std;


ReallyLongInt::ReallyLongInt()
{
  size = 1;
  isNeg = false;
  digits = new vector <bool> (size,0);
}


ReallyLongInt:: ReallyLongInt(long long num)
{

  //cout << " num  " << num <<endl;
    

  if (num < 0) {
    isNeg = true;
    num = num * (-1);
  }
  
  else {
    isNeg = false;
  }

  if(num == 0){
    size = 1;
  }

  else {
    size = (log2(num)) + 1;
  }

  //cout << " num  " << num <<endl;
  
  digits = new vector <bool> (size,0);
  
  long long i = 0;
  
  while (num > 0) { 
    
    if (num%2 == 1) {
      (*digits)[i] = true;
    }
        
    else {
      (*digits)[i] = false;
    }

    num = num / 2;
    i++;
    
  }
}

ReallyLongInt:: ReallyLongInt(const string& numStr)
{

  long long num  = stoll (numStr);
  
  if (num < 0) {
    isNeg = true;
    num = num * (-1);
  }
  
  else {
    isNeg = false;
  }

  if(num == 0){
    size = 1;
  }

  else {
    size = (log2(num)) + 1;
  }

  digits = new vector <bool> (size,0);
  
  long long i = 0;
  
  while (num > 0) { 

    if (num%2 == 1) {
      (*digits)[i] = true;
    }
    
    else {
      (*digits)[i] = false;
    }
    num = num / 2;
    i++;
    
  }
}

ReallyLongInt:: ReallyLongInt(const ReallyLongInt& other)
{

  size = other.size;
  isNeg = other.isNeg;
  
  digits = new vector <bool> (size,isNeg);

  for (long long i = 0; i <= size; i++) {
    
    (*digits)[i] = (*other.digits)[i];
    
  }
}
  

ReallyLongInt::~ReallyLongInt()
{
  delete digits; 
}


string ReallyLongInt::toString() const
{

  string ans;
  long long deci = 0 ;
  int location = 0;
  
  for(int i=size; i >= 0; i--){

    deci = deci + ((*digits)[i]) * pow(2,i);

    location ++;   
  }

  if (this->isNeg) {
    ans = "-" + to_string(deci);
    return ans;
  }
  
  return to_string(deci);
}

string ReallyLongInt::toStringBinary() const
{
  string numb = "";

  for(int i=0; i < size; i++){

    if ((*digits)[i])
      {
	numb = numb + "1";
      }

    else
      {
	numb = numb + "0";
      }
    
  }

  string numbo(numb);
  reverse(numbo.begin(), numbo.end());

  return numbo;

}

void ReallyLongInt::removeLeadingZeros(void)
{

  if (this->size == 1) {
    return ;
  }

  else if ((*digits)[size-1] == 1) {
    return ;
  }

  else if (this->toString() == "0") {
    *this = 0;
  }
  
  else {

    int c = size - 1;

    while ((*digits)[c] != 1) {
      
      c = c - 1;

    }

    unsigned int newsize = c+1;
    vector<bool> *tmpdigits =  new vector <bool> (newsize,false);
    
    for (int i = 0; i <newsize ; i++) {

      (*tmpdigits) [i] = (*digits) [i];

    }

    this->size = newsize;

    this->digits = tmpdigits;
  
  }
}

bool ReallyLongInt::equal (const ReallyLongInt& other) const
{
  
  if (this->size != (other.size)) {
    return false;
  }

  else if ((this->isNeg != (other.isNeg))) {
    return false;
  }
  
  else {

    for (int i = 0; i < size;i++){
      
      if (((*digits)[i]) != (*other.digits)[i] ){
	
	return false;
      }
    }
  }
  
  return true;
}

bool ReallyLongInt::absGreater (const ReallyLongInt& other) const
{

  if(this->equal(other)) {
    return false;
  }
  else if (this->size > (other.size)) {

    return true;
  }
  else if (this->size < (other.size)) {
    
    return false;
  }
  else {
     
    for (int i = 0; i < size; i++) {

      if (((*digits)[i]) > (*other.digits)[i]) {
	return true;
      }
    }
  }
  return false;
}


bool ReallyLongInt::greater (const ReallyLongInt& other) const
{

  if ((this->isNeg == (other.isNeg))) {

    return absGreater(other);
    
  }

  if ((this->isNeg != (other.isNeg))) {

    if ((this->isNeg == false && (other.isNeg) == true)) {

      return true;
    }

    else if ((this->isNeg == true && (other.isNeg) == false)) {
      
      return false;
    }
  }

  return false;
}

void ReallyLongInt::swap(ReallyLongInt other)
{
  ReallyLongInt tempo = ReallyLongInt(other);
  
  std::swap( tempo.size, this->size);
  std::swap( tempo.isNeg,this->isNeg);
  std::swap(tempo.digits, this->digits);
}

ReallyLongInt& ReallyLongInt:: operator=(const ReallyLongInt& other)
{
  swap(other);
  return *this;
}

ReallyLongInt ReallyLongInt:: absAdd(const ReallyLongInt& other) const
{
  int maxSize = 0;

  //ReallyLongInt a (stoi((*this).toString()));

  if (this->size > other.size) {

    maxSize = this->size + 1;
  }

  else {

    maxSize = other.size + 1;
  }

  vector<bool> *tmpdigits =  new vector <bool> (maxSize,false);

  
  
  if (this->size > other.size) {

    int carry = 0;
    for (int i = 0; i < other.size; i++) {
      int sum = ((*digits)[i]) +  ((*other.digits)[i]) + carry;
      carry = sum / 2 ;
      (*tmpdigits) [i] = sum % 2;
    }

    for (int j = other.size; j < maxSize;j++) {
      int sum = ((*digits)[j]) +  0 + carry;
      carry = sum / 2 ;
      (*tmpdigits) [j] = sum % 2;
    }
  }
  
  else {

    int carry = 0;
    for (int i = 0; i < this->size; i++) {
      int sum = ((*digits)[i]) +  ((*other.digits)[i]) + carry;
      carry = sum / 2 ;
      (*tmpdigits) [i] = sum % 2;
    }

    for (int j = this->size; j < maxSize;j++) {
      int sum = 0 +   ((*other.digits)[j]) + carry;
      carry = sum / 2 ;
      (*tmpdigits) [j] = sum % 2;
    }
  }
  
  ReallyLongInt fin;
  *fin.digits = *tmpdigits;
  fin.size = maxSize;
  fin.isNeg = false;
  fin.removeLeadingZeros();
  return fin;
}


ReallyLongInt ReallyLongInt:: absSub(const ReallyLongInt& other) const
{
  int maxSize = 0;
  
  if (this->size > other.size) {
    maxSize = this->size ;
  }

  else {
    maxSize = other.size ;
  }

 
  vector<bool> *tmpdigits =  new vector <bool> (maxSize,false);

  if(this->absGreater(other)) {
    
    //if (this->size > other.size) {
      
      int borrow = 0;
      
      for (int i = 0; i < other.size; i++) {

	int c = i;

	if (((*digits)[i]) == 1 && (*other.digits)[i] == 0) {
	  (*tmpdigits) [i] = 1;
	}
	else if (((*digits)[i]) == 1 && (*other.digits)[i] == 1) {
	  (*tmpdigits) [i] = 0;
	}
	else if (((*digits)[i]) == 0 && (*other.digits)[i] == 0) {
	  (*tmpdigits) [i] = 0;
	}
	
	else if (((*digits)[i]) == 0 && (*other.digits)[i] == 1) {
	  
	  
	  
	  while ((*digits)[c] == 0) {
	    c++;
	  }
	  (*digits)[c] = 0;
	  for (int j = c-1; j > i; j--) {
	    (*digits)[j] = 1;  
	    
	  }

	  (*tmpdigits) [i] = 1;
	}
	
      }
   
    
    for (int j = other.size; j < maxSize;j++) {
      

      (*tmpdigits) [j] = (*digits)[j];
	
    }
  }
  
  else if (this->absGreater(other) == false){
    
    int borrow = 0;
    
    for (int i = 0; i < this->size; i++) {
      
      
      int c = i;
      
      
	if (((*digits)[i]) == 0 && (*other.digits)[i] == 1) {
	  (*tmpdigits) [i] = 1;
	}
	else if (((*digits)[i]) == 1 && (*other.digits)[i] == 1) {
	  (*tmpdigits) [i] = 0;
	}
	else if (((*digits)[i]) == 0 && (*other.digits)[i] == 0) {
	  (*tmpdigits) [i] = 0;
	}

	else if (((*digits)[i]) == 1 && (*other.digits)[i] == 0) {
	  
	  
	  while ((*other.digits)[c] == 0) {
	    c++;
	  }
	  (*other.digits)[c] = 0;
	  for (int j = c-1; j > i; j--) {
	    (*other.digits)[j] = 1;  
	    
	  }

	  (*tmpdigits) [i] = 1;
	}
    }
    
    for (int j = this->size ; j < maxSize;j++) {
      
  
      (*tmpdigits) [j] = (*other.digits)[j];

    }
      
  }

  ReallyLongInt fin;
  *fin.digits = *tmpdigits;
  fin.size = maxSize;
  fin.isNeg = false;
  fin.removeLeadingZeros();
  return fin;
}




ReallyLongInt ReallyLongInt:: add(const ReallyLongInt& other) const
{

  if(this->isNeg == false and other.isNeg == false) {
    
    return absAdd(other);
  }

  if(this->isNeg == false and other.isNeg == true and this->absGreater(other)) {

    
        
    ReallyLongInt a(other);
    ReallyLongInt b(*this);
    
    return absAdd(other);

  }

  if(this->isNeg == false and other.isNeg == true and !(this->absGreater(other))) {

    
        
    ReallyLongInt a(other);
    ReallyLongInt b(*this);
    
    return -absAdd(other);

  }

  
  if(this->isNeg == true and other.isNeg == false and this->absGreater(other)) {

    ReallyLongInt a(*this);
    a.flipSign();
    return -(a.absSub(other));

  }

   if(this->isNeg == true and other.isNeg == false and this->absGreater(other) == false) {

    ReallyLongInt a(*this);
    a.flipSign();
    return (a.absSub(other));

  }

  if(this->isNeg == true and other.isNeg == true) {

    //check this is wrong
    
    ReallyLongInt a(other);
    ReallyLongInt b(*this);
    
    a.flipSign();
    b.flipSign();
        
    return -(a.absAdd(b));

  }
 
}

ReallyLongInt ReallyLongInt:: sub(const ReallyLongInt& other) const
{
  //cout << " this =  " << (*this).toString() <<endl;
  
  //cout << " this =  " << other.toString() <<endl;

  if((*this).equal(1) and other.equal(0)) {

    
    //cout << " goes into desired if state  " << (*this).toString() <<endl;
  
    
     return (1);
  }

  else if((*this).equal(0) and other.equal(1)) {

    
    //cout << " goes into desired if state  " << (*this).toString() <<endl;
  
    
     return (1);
  }

  else if(this->isNeg == false and other.isNeg == false and this->absGreater(other)) {
    
    return absSub(other);
  }
  
  else if(this->isNeg == false and other.isNeg == false and !this->absGreater(other)) {
    
    return -absSub(other);
  }
  
  
   
   
  else if(this->isNeg == false and other.isNeg == true) {

    ReallyLongInt a(other);

    a.flipSign();
    
    return (absAdd(a));

   }
   
  else if(this->isNeg == true and other.isNeg == false ) {
     
     ReallyLongInt a(*this);
     ReallyLongInt b(other);
     
     a.flipSign();
     
     return -a.absAdd(other);
     
   }

  else if(this->isNeg == true and other.isNeg == true and this->size == other.size) {

    ReallyLongInt a(*this);
    ReallyLongInt b(other);
  
    a.flipSign();
    b.flipSign();
    ReallyLongInt fina (a.absAdd(b));
    fina.flipSign();
    return (fina);

  }

  else if(this->isNeg == true and other.isNeg == true) {

    //cout << "a  " << (*this).toString() <<endl;
    ReallyLongInt a(*this);
    ReallyLongInt b(other);

   

    
    a.flipSign();
    b.flipSign();

    //cout << "a  " << a.toString() <<endl;

    if( a.absGreater(b)) {

      
      
      ReallyLongInt fina (a.absSub(b));
      
      //fina.flipSign();
      
      return -(fina);
      
    }

    else {
      
      return (b.absSub(a));

    }}

}

void ReallyLongInt::flipSign()
{
  
  if (toString() == "0") {
    isNeg = false ;
  }
  else {
    
    if (isNeg == false) {
      isNeg = true ;
    }
    
    else {
      isNeg = false;

    }
  }
}

ReallyLongInt ReallyLongInt:: absMult(const ReallyLongInt& other) const
{
  
  int maxSize = this->size + other.size;  
  vector<bool> *tmpdigits =  new vector <bool> (maxSize,false);
  
  if(this->absGreater(other)) {

    int x = 0;

    for (int i = 0; i <= other.size; i++) {

      for (int j = 0; j < this->size; j++) {

	int num = ((*digits)[j]) *  ((*other.digits)[i]);

	if ((*tmpdigits) [x] == 0 and num == 0){
	  (*tmpdigits) [x] = 0;
	}

	else if ((*tmpdigits) [x] == 0 and num == 1){
	  (*tmpdigits) [x] = 1;
	}


	else if ((*tmpdigits) [x] == 1 and num == 1){
	  
	  int c = x;
	  while ((*tmpdigits)[c] != 0) {
	    c++;
	  }
	  
	  (*tmpdigits) [c] = 1;

	  for (int k = c-1; k >= x; k--) {
	    
	    (*tmpdigits)[k] = 0;
	    
	  }
	}
	else if ((*tmpdigits) [x] == 1 and num == 0){
	  (*tmpdigits) [x] = 1;
	}
	x++;
      }
      x = i+1;
      
    }
  }
  
  else {

    int x = 0;
    for (int i = 0; i <= this->size; i++) {

      
      for (int j = 0; j < other.size; j++) {
	int num = ((*digits)[i]) *  ((*other.digits)[j]);

	
	if ((*tmpdigits) [x] == 0 and num == 0){
	  (*tmpdigits) [x] = 0;
	}

	else if ((*tmpdigits) [x] == 0 and num == 1){
	  (*tmpdigits) [x] = 1;
	}
	else if ((*tmpdigits) [x] == 1 and num == 1){
	  
	  int c = x;
	  while ((*tmpdigits)[c] != 0) {
	    c++;
	  }

	  (*tmpdigits) [c] = 1;

	  for (int k = c-1; k >= x; k--) {
	    (*tmpdigits)[k] = 0;
	    
	  }
	  
	}
	
	else if ((*tmpdigits) [x] == 1 and num == 0){
	  
	  (*tmpdigits) [x] = 1;
	}
	x++;
      }
      x = i+1;
    }
  }

  ReallyLongInt fin;
  *fin.digits = *tmpdigits;
  fin.size = maxSize;
  fin.isNeg = false;
  fin.removeLeadingZeros();
  return fin;
}

ReallyLongInt ReallyLongInt:: mult(const ReallyLongInt& other) const
{

   if(this->isNeg == false and other.isNeg == false) {

    return absMult(other);
  }

   if(this->isNeg == false and other.isNeg == true) {

     ReallyLongInt a(other);

     a.flipSign();
     
     return -absMult(a);

   }

   if(this->isNeg == true and other.isNeg == false) {

     ReallyLongInt a(other);
     ReallyLongInt b(*this);

     b.flipSign();
     
     return -b.absMult(a);

   }

    if(this->isNeg == true and other.isNeg == true) {

     ReallyLongInt a(other);
     ReallyLongInt b(*this);

     a.flipSign();
     b.flipSign();
     
     return (b.absMult(a));

   }
    
}

ReallyLongInt ReallyLongInt:: operator-() const
{
  ReallyLongInt chan = *this;
  chan.flipSign();
  return chan;
  
}

ReallyLongInt operator+(const ReallyLongInt& x, const ReallyLongInt& y)
{
  return x.add(y);
}

ReallyLongInt operator-(const ReallyLongInt& x, const ReallyLongInt& y)
{
  return x.sub(y);
}

ReallyLongInt operator*(const ReallyLongInt& x, const ReallyLongInt& y)
{
  return x.mult(y);
}



void ReallyLongInt::absDiv(const ReallyLongInt& other, ReallyLongInt& quotient,ReallyLongInt& remainder) const
{
  
  
  ReallyLongInt r(0);
  ReallyLongInt d(0);
  ReallyLongInt q(0);

  vector<bool> *tmpdigits =  new vector <bool> (size,false);

  //cout << " -------------- Starting Abs Div ------------------ " <<endl;

  //cout << "value of this before for loop =  " << (*this).toString() <<endl;
  //cout << "value of other before for loop =  " << other.toString() <<endl;
  
  for ( int i = size-1; i >= 0; i--){

    r = 2*r;
    if (((*digits)[i])) {
      r = r+1  ;
    }
    
    d = 0;

    //cout << " value of remainder before while loop =  " << r.toString() <<endl;
    
    while (other.absGreater(r) == false) {

      //cout << " goes into while loop & other is " << other.toString() <<endl;
      
      r = r.sub(other);
      d = d+1;
    }

    
    //cout << " value Of r after while loop  =  " << r.toString() <<endl;
    
    d = d*(pow(2,i));
    q = q + d;
  }
  
  remainder = r;
  quotient = q;

  //cout << " -------------- Abs Div Ends ------------------ " <<endl;
  
}

void ReallyLongInt::div(const ReallyLongInt& other, ReallyLongInt& quotient,ReallyLongInt& remainder) const

{

  if((*this).toString() == "0") {

    //cout << "Testing Zero !!!  " << endl;

    return;   
    
  }

  else if(other.toString() == "0") {
    
    //cout << "Testing Zero On Top !!!  " << endl;

    return;   
    
    }
  
  
  else if(isNeg == true &&  other.isNeg == true) {
    
    
    //cout << "This  " << (*this).toString() <<endl;
    //cout << "Other  " << other.toString() <<endl;
    ReallyLongInt a(*this);
    ReallyLongInt b(other);

    a.flipSign();
    b.flipSign();

    //cout << "a  " << a.toString() <<endl;
    //cout << "b  " << b.toString() <<endl;
    
    a.absDiv(b, quotient, remainder);

    //cout << "quotient  " << quotient.toString() <<endl;
    //cout << "remainder  " << remainder.toString() <<endl;
    
  }
  
  else if(isNeg == false &&  other.isNeg == true) {
    
    ReallyLongInt a(*this);
    ReallyLongInt b(other);

    //a.flipSign();
    b.flipSign();

    a.absDiv(b, quotient, remainder);
    quotient.flipSign();
    remainder.flipSign();

    
    
  }
  else if(isNeg == true &&  other.isNeg == false) {
    
    ReallyLongInt a(*this);
    ReallyLongInt b(other);

    a.flipSign();
    //b.flipSign();

    a.absDiv(b, quotient, remainder);
    quotient.flipSign();
    remainder.flipSign();

    
    
  }

  else {
    
     (*this).absDiv(other, quotient, remainder);

  }

}

ReallyLongInt operator/(const ReallyLongInt& x,const ReallyLongInt& y)
{

  ReallyLongInt q;
  ReallyLongInt r;
  
  x.div (y, q, r);
  return q;
  
}

ReallyLongInt operator%(const ReallyLongInt& x,const ReallyLongInt& y)
{

  
  ReallyLongInt q;
  ReallyLongInt r;
  
  x.div (y, q, r);
  return r;

  
}

bool ReallyLongInt:: even (const ReallyLongInt& other) const 
{

  int lastD = (*other.digits)[0];

  if (lastD == 1) {

    return false;
  }

  else {

    return true;
  }
  
}



ReallyLongInt ReallyLongInt:: exp (ReallyLongInt e )const
{

  //cout << "Testing Exp !!!  " << even(e) <<endl;
  
  if (even(e)) {

    if (e.equal(0)) {
      ReallyLongInt f(1);
      return f;
    }
    else {
      return (((*this).exp(e/2)) * ((*this).exp(e/2)));
    }
  }
  
  else {

    if (e.equal(0)) {
      ReallyLongInt f(1);
      return f;
    }
    
    else {
      return ((*this)*(((*this).exp(e/2)) * ((*this).exp(e/2))));
    }
  }
  
}

bool ReallyLongInt:: isPrime () const 
{

  //ReallyLongInt fin = other;
  //(*this).removeLeadingZeros();

  //cout << "Size  " << this->size <<endl;
  

  int s = this->size;

  int lastD = (*digits)[0];
  int firstD = (*digits)[s-1];

  //cout << "Number  " << (*this).toStringBinary() <<endl;
  
  //cout << "lastD  " << lastD <<endl;
  //cout << "firstD  " << firstD <<endl;
  
  if (lastD == 1 and firstD == 1) {
    
    return true;
  }

  else if ((*this).toString() == "2") {

    return true;

  }

  else {
    
    return false;
  }
  
}











       

      
       





















  
