//Functions 
//example : 4.3

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std; 

//function declaration  and the definition are at the same block 

//type name (parameter list)
// |    |    |
// \/   \/   \/
double power(double x, int n){ // declaration of a function 
  /////////////////////
  //function defition/////////
                            //
  double y = 1.0;           //  
  for(int i=0; i<n ;i++){   //
    y *= x;                 //
  }                         //
  return y;                 //
  ////////////////////////////
}


//example 4.4 
// separate the function declaration from the definition of it 

//declaration of the function power1 
double power1(double x, int n);


//declaration of the function power2 : we can choose not to 
//write names of the parameters in declaration 
double power2(double , int);


//main function : where the other functions power and power1 
//is called 

int main(){ // main is also a function

  cout << power(2.0,2) << endl; 
  cout << power1(2.0,3) << endl; 
  cout << power2(2.0,4) << endl; 

  return 0; // main functions return type is int, so usually we put retrun 0
}



//definition of the function power1

double power1(double x , int n ){

  double y = 1.0 ; 
  for(int i =0 ; i<n ; i++){
  y *= x; 
  }
  return y;
}


//definiton of the function power2 : here we must write the name of the 
// parameters in the parenthesis 
double power2(double x , int n ){

  double y = 1.0 ; 
  for(int i =0 ; i<n ; i++){
  y *= x; 
  }
  return y;
}
