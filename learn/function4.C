// one function calling other function 
// compile: g++ -o function4 function4.C ->will produce an executable: function4
// then run the executable ./function4

#include <iostream>
#include <string>


using namespace std;

double addChange(double n1In, double n2In)
{
  
  return n1In + n2In; 
}

string chooseFood(double amountIn)
{
  if (amountIn >= 1.50)
    return "Hot Dog!";
  else
    return "Doughnut";
}


int main(){

  double left  = 1.1;
  double right = 2.2;
  
  cout << addChange(left, right) << endl;;
  

  cout << chooseFood(addChange(left,right)) << endl;


  return 0;
}
