//chapter 2 : C++ fundamentals 
//example upto 2.16

#include <iomanip> // boolalpha flap is defined here
#include <iostream>

using namespace std;

int main(){

  //normally bool are printed as 0 or 1 
  cout <<"false : "  << false << endl;
  cout <<"true  : "  << true  << endl; 
  //once the boolalpha flag is used in the code 
  //that can be overridden and can be printed as false or true 
  cout << boolalpha  << true << endl; 
  cout << false << endl ;

  char ch = 'A'; // the char 'A' is stored in one byte as the integer 65
  char ch1 = 'B';
  char ch2 = 'C';
  
  cout <<"ch : " << ch << endl ;
  //int is used the cast value of ch from char to int 
  cout <<"int(ch) : "<< int(ch) << endl;
  cout <<"ch1 : "<< ch1 << endl; 
  cout <<"int(ch1) : "<< int(ch1) << endl;
 

  /////////////////////
  //// error //////////
  /////////////////////
  //char ch3 = 'EF'; //not possible : error : 
  //compilation error : 
  //2.cpp:30:14: warning: multi-character character constant [-Wmultichar]
  // char ch3 = 'EF'; //not possible : error : 
  //            ^
  //f2.cpp: In function ‘int main()’:
  //f2.cpp:30:14: warning: overflow in implicit constant conversion [-Woverflow]


  ////////////////////////
  /// enumeration type ///
  ////////////////////////

  //enum is user defined type that consists of integral constants. 'enum' is 
  //the keyword for the enumeration type. by default here N will take 0,
  // S will take 1 and so on  

  enum DIRECTION {N, S, E, W};
  // DIRECTION CURRENT = N ; 
  cout <<"N : "  << N << endl; 
  cout <<"S : "  << S << endl;
  cout <<"E : "  << E << endl;
  cout <<"W : "  << W << endl;

  // default values can be chaged during declaration 

  enum DIRECTION1 {N1 = 100, S1 =120, E1 =130, W1 = 140};
  // DIRECTION CURRENT = N ; 
  cout <<"N1 : "  << N1 << endl; 
  cout <<"S1 : "  << S1 << endl;
  cout <<"E1 : "  << E1 << endl;
  cout <<"W1 : "  << W1 << endl;


}

