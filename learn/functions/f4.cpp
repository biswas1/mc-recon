//example 4.12, 4.13
// passing of argument : 4 types -> 1) const 2) const value 3) reference 
// 4)const reference  

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std; 

void f2(int x){ // x is called parameter of the function 
  //argument is passed as the value here 
  // cout << " x val = " << x << endl;
  x ++;
  cout << " x val = "<< x << endl;
}

void f3(const int x){
  //  passing the argument to parameter by " const value "
  //  x++; // this will give error "increment of read-only parameter ‘x’ "
  // its a read only parameter cannot change the value inside the function 

  cout << " f3(x) = "<< x << endl; 
}

void f4(int &x){

  cout << "x (before change )= "<< x << endl; 
  x ++;
  cout << "x (after change ) = "<< x << endl; 
}

void f5(const int &x){
  // when argument passed by const ref, its same as passing by ref BUT 
  // cannot change its value 
  cout <<"f4(x) = " << x << endl; 
}


int main(){

int u = 33; // u is called the argument 
// argument is passed to parameter in function 

//argument passed as value 
f2(44);
f2(u);
//changing x's value of function does not affect the value of u here 
cout << "u after passing to x as value = " << u << endl;


//argument passed as "const value" 
int v = 44; 
f3(v);
cout << "v after passing to x as const value = " << v << endl; 

//argument passed by "reference "
 int w = 55; 
 f4(w);
 //if we change the x in fucntion it changes the value of w
 cout << "w after passing the x as ref = " << w << endl; 
 // const int  w = 55; cannot be passed as its read -only, no value can be assigned to const 
 // int w = u+v; expressions cannot be passed , read- only , no value can be assigned to the expression
 // on the other hand when we pass the argument as ref , parameter (e.g. x here ) does not have its own storage space , its just another name for w 


 // argument passed by the "const ref"
 int n = 66; 
 f5(n);
 // chnaging the arguments value in the function is prohibited
 //so no question fo chnaging the value of n  
 cout << "n = " << n <<endl; 
}
