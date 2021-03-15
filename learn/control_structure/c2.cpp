//example 3.6 - 3.16 

#include <iostream>

#include <iomanip>

#include <cmath>

using namespace std; 

int main(){

  cout << "test" << endl;

  int x; 

  cout << "value of x = " << endl;
  cin >> x ;
  //conditional expression operator 

  int abs_x = (x>=0 ? x : -x);

  cout << "abs x = |x| = " << abs_x << endl; 

  //using conditional expression operator in the cout statement 

  cout << "You " << (x>=60 ? "passed" : "failed") << " the test .\n";


  //while loop 
  int n = 1; 
  int sum = 0; 
  while(n<=100){
    sum += n*n;
    n++;
  }
  cout <<" sum : " << sum << endl; 

  int m = 0;
  int sum1 = 0;
  //following equvalent 
  while(++m < 100){
    sum1 += m*m;
  }
  cout <<" sum1 : " << sum1 << endl;
}
