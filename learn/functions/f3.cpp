

#include <iostream>

#include <cmath>

#include <iomanip>

#include <assert.h>

using namespace std;

//example 4.10 : Predicates : is a function whose return type is boolean. 
// to check certain conditions about the argument

bool even( int n){
  assert(n > 0);
  if(n==1) return false;
  if(n==2) return true;
  if(n % 2 == 0) return true;
  if(n % 2 != 0) return false;
  
}

//example 4.11 : Default Arguments : when some value of arguments are specified
//while declaration fo the function. The argument will take the default values
//unless otherwise specified   

int add(int a=1, int b=2){

  return (a+b);
}


int main(){
  int n;
  cout << " Enter the Iteger number : " << endl;
  cin >> n;
  assert(n >0);
  if(even(n)) {cout << n << " is even !" << endl; } else{ 
    cout << n << " is odd!" << endl; };


  cout << " default values for a, b : add() = " << add() << endl;

  // we can also insert specific values for the a, b; then the default values
  // will be overriden by the new given values 

  cout << " user defined values for a,b : add(4,3) = " << add(4,3) << endl; 
  
  // when user inputs only 1 argument

  cout << "user puts less than the required number of  arguments " << add(4) << endl;  


}
