//chapter 2 C++ fundamentals

//example 2.17 - 2.18


#include <iostream>

#include <iomanip> // standard C++ library 

#include <cmath> // standard C++ library 

using namespace std;


// this program will illustrate the <iomanip> file
int main(){

  int n= 75; 

  cout <<" print n in octal : " << oct << n << endl; 
  cout <<" print n in hexadecimal : " << hex << n << endl; 
  cout <<" print n in decimal : " << dec << n << endl;
  //right justify output : default justification within the field
  cout <<" print from 5th postion towards left : " << setw(5) << n << endl;
  cout <<setfill('.')<<setw(5) << n << endl;
  cout <<setfill('*')<<setw(5) << n << endl;
  //left justify output 
  cout.setf(ios::left, ios::adjustfield);
   cout <<setfill('.')<<setw(5) << n << endl;
   cout.setf(ios::right, ios::adjustfield);
   const double PI = 3.1415926535 ;
   cout << setprecision(5) << PI << endl; 
   cout <<setprecision(10) << PI << endl;
   //16 is the maximum number of accurate digits obtainable for a double 
   //on this computer 
   cout <<"not accurate with preciison 22:" << endl;
   cout <<setprecision(22) << PI << endl; 



   //using some functions of the standard library <cmath>

   double x = 2.7153564789736525637484; 
   cout << "ceil(x) = " << ceil(x) << endl; //ceil <-> ceiling
   cout << "floor(x) = " << floor(x) << endl; 
   cout << "sqrt(x) = " << sqrt(x) << endl;
   cout << "pow(x, 0.5) = " << pow(x, 0.5) << endl;
   cout << "log(x) = " << log(x) << endl; 
   cout << "log10(x) = " << log10(x) << endl; 
   cout << "exp(x) = "<< exp(x) << endl; 
   cout << "sin(x) = "<<sin(x) <<endl; 
}
