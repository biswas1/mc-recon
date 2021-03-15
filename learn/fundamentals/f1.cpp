//Scahum's series c++ : chapter 2 : C++ Fundamentals 

//example 2.1 - 2.9

//#include <iostream> : this is called the precompiler directives 
//this line asks the precompiler to copy all the source code from 
//the file "iostream" , "iostream" file is a part of the ISO standard
//C++ library. this is required for any program which has an input and output 
 
#include <iostream>

//want to use some names (e.g. cout ) which is defined in std namespace 
using namespace std;

//every c++ program will have the section int main() :: ehich is called main 
// function 
int main(){

  cout << "hello world !\n"; 
  //\n : new line charater
  //<< : insertion character, means the string should be inserted into the output stream cout 

  int n; //declaration of 'VARIABLE' n of the 'TYPE' integer
  n = 44; // assigined a value 44 to n ; '='assignment operator; 'n=44' assigment statement 
  cout << " The value of n is : " << n << '\n' ;

  int m; 
  cin >> m; // cin : output stream; >> : extraction operator  
  cout << "m = " << m << '\n';

  // The "MODULOUS : %" operator
  //provides the remainder of the divison m/n
  cout << "m%n = " << m%n << '\n' ;
  cout << "n%m = " << n%m << '\n' ;
 
  //pre increment and post increment operator (++)
  cout <<" n++ = " << n++ <<'\n'; // print n=44 then increment by 1
  cout <<"n = " << n << '\n' ; // will print 45
  cout <<"++n = " << ++n << '\n'; // icremanet by 1 and then print, hence will print 46
  n += 5; // n =n+5
  cout << "n += 5 : " << n <<'\n';
  n *= n; // n = n*n
  cout << "n *= n : " << n << '\n';
  m %= 2; // m = m%2
  cout << m <<'\n';
  cout << 4%3 << endl; // reminder of (4/3)

  // int p; 
  //cout << p << endl ;
  int p = 50 ; // this is initialization : initializaton is not same as assignment

  cout<< p << endl; 

  const int q = 90; // const must be initalized when declairing 
  cout << "constant q = " << q <<'\n'; 
  // q = 32 ; not possible value of the constant cannot te reassigned later
  
  //some compiler needs "return 0;" at the end of the main function 
  return 0;

}
