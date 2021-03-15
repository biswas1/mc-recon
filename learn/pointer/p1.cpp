//example program for the pointer : from chapter 8 schaum's series : Fundamentals of computing with C++

//from example 8.1 to 8.5 (revised version)

#include <iostream>

using namespace std;

int n = 22; 

//initializinf a class
class print{
  //define the member function of type  public 
public :
  int print_int(){
    return n; 
  }
  
};


int main(){
  //pointer is an object whose value is the memory location of the of the first
  //byte occupier by int n 

  int* p = &n;

  cout << "memory lecation of the 1st byte of n, p= "  << p << endl;  
  cout << "the pinter is dereferenced in here *p = " << *p << endl; 

  //define a pointer q
  int *q;
  //initializing the pointer q 
  q = p; // value of p is coppied to q 
  cout <<"  " << endl; 
  cout << "p = " << p << " ;q = " << q << endl; 
  cout <<"*p = "<< *p << " ;*q = "<< *q << endl; 
  cout <<" "<<endl; 
  cout <<"----------------" << endl; 
  //declair the object of the class print
  print obj1;
  //define a pointer which will points to that object 
  print* p1 = &obj1;

  //three ways to access the member function of the class //
  //1. directly through the object 
  cout << "obj1.print_int() = " << obj1.print_int() << endl ;
  //2. access the member function through the pointer (method 1)//
  cout << "(*p1).print_int() = " << (*p1).print_int() << endl ;
  //3. access the member function through thr pointer (method2) //
  cout << "p1->print_int() = " << p1->print_int() << endl; 
  

  //p1 itseft hold the memory location //
  cout << "p1 : " << p1 << endl;



}
