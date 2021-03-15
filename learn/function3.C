//work with return type and the parameters of the functions

#include <iostream>

using namespace std;



// Return Type - Function Name - [parameters]

int addNumbers(int num1In, int num2In)
{
  // if the return type is anything but void (e.g. int here) need to use return 
  // keyword
  return num1In + num2In ; 
}


int function3(){
  
  addNumbers(1,2);
  
  // at this point it will run but will not print anything on screen 
  // as we did not say it what to do with the return 

  //now we will do something with the return value 
  cout << addNumbers(1,2) ;
  return 0;
}
