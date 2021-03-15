//chapter 2 

//example  : 2.19 - 

#include <iostream>

#include <cmath>

#include <iomanip>

using namespace std;

int main(){

  //errors

  //syntax error 

  //compile - time error 
  //write "count" instead of "cout"

  //link time error 
  //do not include <iostream> standard library and try to use "cout"



  //run-time error : example integer overflow

  int n = 2000;
  n *=n;
  cout << "(n*n) = " << n << endl; 
  n*=n;
  //it will give a wrong answer , because the ans is too large for an integer 
  //type. This error is called the integer overflow
  cout <<"(n*n*n*n) = " << n << endl; 

  //round off error : divison by zero & function arguments that are out of 
  //range 

  float a = 1e0; // == 1.0
  float b = -1e10; // == - 10000000000.0
  float c = 1e0; // == 1.0
  float d = b*b - 4*a*c;
  
  float x1 = (-b + sqrt(d))/(2.0*a);
  float x2 = (-b - sqrt(d)) / (2.0*a);
  // this will give a wrong answer due to round-off error 
  cout << "x1 = " << x1 <<" ,x2 = " << x2 <<endl; 

  //logical errors
}
