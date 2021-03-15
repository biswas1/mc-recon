#include <iostream>



using namespace std;

void printGreeting() // declaration line of the function 
//body of the function starting
{
  cout << "body of the function\n" ;

}

void printCursing()

{

  cout << "you are horrible \n" ;
}

//main program body 
int function1(){


  //call the function simply by writing the name 
  printGreeting();
  //calling another function
  printCursing();
  return 0; 

}
