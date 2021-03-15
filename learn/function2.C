#include <iostream>

using namespace std;

//return type - function name - ([parameters]) ::::[]: means anything inside []
//are optional

//make a function which will take two numbers and add them together 

//return  function  argument1      argument2
//type    name                       
//  |     |            |              |
//  |     |            |              |
//  V     V            V              V
  void addNumbers(int number1In, int number2In)
  {
    //put a mathmetical formula
    cout << number1In + number2In;
  }



int function2(){

  int a = 5;
  int b = 6;

  addNumbers(a,b);
  cout<< endl; 
  addNumbers(1,4);
  
  return 0 ;
}
