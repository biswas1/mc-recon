//function with more than 1 return statement 
//example 4.5 

#include <iostream>

#include <cmath>

#include <iomanip>

#include <assert.h> // ***

using namespace std; 

int factorial(int n){
  assert(n >= 0); // its a nice function we can call from <assert.h> which
  //is included ****// by this way programmer tells the program that program
  // shoud expect the positive n , so if in anyway porogrammer put negative 
  //value of the n, the program will be abborted 

  if (n<2) return 1; //  0!=1, 1!=1 

  
  while(n>1){
    int y = 1.0; 
    for(int i =0; i<n ; i++){
      y *= n-- ;
    }
    return y;
  }
}


//example 4.6
//void type function : where there is to return value of the function 

void print_literal_digit(int n){
  assert(n<=2 && n>=0);
  if (n==0) cout << "zero" << endl; 
  else if(n==1) cout << "one" << endl;
  else if(n==2) cout << "two" << endl;
}


int main(){

  cout << factorial(0) << endl; 

  //calling a void type function using its name as an executable statement 
  print_literal_digit(2) ;

}

