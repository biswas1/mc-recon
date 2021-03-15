//chapter 3: control structure

//example 3.17  

#include <iostream>

#include <iomanip>

#include <cmath>

using namespace std;

int main(){

  // controlling a loop interactively with the End-of-File signal
  // to end the program Cntrl + d (for UNIX and windows )
  float x; 
  float sum = 0.0;
  //when input x is float (cin >> x) returns a bool true 
  //otherwise it returns the bool false 
  while (cin >> x)
    sum += x;
  cout << "sum = " << sum << endl;


 

}
