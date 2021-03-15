//////////////////////////
///// include files //////
//////////////////////////

#include <iostream>
#include "hdr.hh"

//#include <iostream>

using namespace std; 



int main(){
  
 
  // double h = 10.0;
  // double l = 5.0;

  double h, l ;
  cout << " h =" ; 
  cin >> h ; 

  cout << " l =" ;
  cin >> l ; 


  Class1 obj1;
  obj1.method1();


  Class1 obj2;
  obj2.method2();


  Class1 obj3;

  // cout <<" addition of two numbers : "  << obj3.method3() << endl; 
  obj3.AddTwoNumbers(h, l);
  // return 0;

  Class2 obj4;
  obj4.SubtractTwoNumbers(h, l);

  
  
}





////////////////
// How to run //
////////////////
// compile :  g++ hdr.hh class1.cpp -o main main.cxx
// this will make an executable
// run : ./main

///////////////
// MakeFiles //
///////////////

// >> make
// will make an executable main 
// run : ./main 
