//Schaum series chapter 8 
// example from 8.7 to 8.9 



#include <iostream>

using namespace std;

main(){

  char s[]={"ABCDEFGH"};

  cout <<"prints all the char in s : " << s << endl;
  cout <<" print the 3rd element of s : " << s[3] << endl; 



  //pointer points to s[3]
  char* p = &s[3];
  cout << " p points to s[3] : *p = " << *p << endl;
  //pointer arithmatic //
  //points p to s[4] by the arithmatic  
  ++p;
  cout <<" p points to s[4] : *p = " << *p << endl; 
  //move the points 3 position in s[]
  p +=3;
  cout <<" p points to s[7] : *p = " << *p << endl; 
  p -=2;
  cout << *p << endl;


  //a pointer can be subtracted from another pointer //
  char* q = &s[4];
  cout <<" p  = " << p << endl;
  cout <<" *p = " << *p << endl;
  cout <<" *q = " << *q << endl;
  cout <<"p-q = " << p-q << endl; 
  //a char takes 1 byte. so if p is initialized to some char(e.g. s[3])
  //then increase by 1, i.e. ++p;
  //then p is incrased by 1 and now points to s[4]

  //cheks what happens when its not char , its int 

  int a[] = {11, 22, 33, 44, 55, 66, 77, 88, 99};
  //initialize the pointer r to a[3]
  int* r = &a[3];
  cout << "r = "<< r << endl;
  cout << "*r = "<< *r << endl;  
  //increase the pointer by 1
  ++r;
  cout <<" increased by 1 and cout r = " << r <<endl;
  cout <<" increased by 1 and cout *r = " << *r <<endl;
  //note that 0x7fffda91996c + 4 bytes = 0x7fffda919970 ;
  //for int the value of pointer increase by 4 bytes 

  // checks what happens with double 


  double b[] = {11.1, 22.2, 33.3, 44.4, 55.5, 66.6, 77.7, 88.8, 99.9};
  //initialize the pointer r to a[3]
  double* t = &b[3];
  cout << "t = "<< t << endl;
  cout << "*t = "<< *t << endl;  
  //increase the pointer by 1
  ++t;
  cout <<" increased by 1 and cout t = " << t <<endl;
  cout <<" increased by 1 and cout *t = " << *t <<endl;
  //note that 0x7fff54622908 + 4 bytes = 0x7fff54622910 ;
  //for int the value of pointer increase by 8 bytes

  //each "double" consume 8 bytes in memory 
  //each "int" consume 4 bytes in memory 
  //each "char" consumes 1 bit in memory  
 
}
