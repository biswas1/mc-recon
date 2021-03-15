//example 4.15 Returning by Reference 

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std; 

int& f1(int &x){

  x ++;
  cout << x << endl;

}


int main(){
  int u= 22;
  f1(u);
  cout << "u = " << u << endl; 
}
