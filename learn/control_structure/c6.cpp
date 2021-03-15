//example 3.24

#include <iostream>

#include <iomanip>

#include <cmath>

using namespace std; 

int main(){

  setiosflags(ios::right); // this is a method of iomanip library   
  int n; 
  cout << "How many columns ? " ;
  cin >> n; 

  for(int x=1; x<=n; x++ ){
    for(int y=1; y<=n; y++){
      cout <<setw(3) << x*y;
    }
    cout << endl; 
  }
  
}
