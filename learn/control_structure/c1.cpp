//chapter 3 : control structures 
//example 3.3 -3.5

#include <iostream>

#include <cmath>

#include <iomanip>

using namespace std;


int x = 11; 

namespace Block1 //Block1 is the name of the Block
{
  int xb1 = 33;
}

 namespace Block2
  {    
    int xb2 = 44 ;    
  }
 
namespace Block3
{
namespace Block3_1
{

  int xb3_1 = 66;
}
}
int main(){

  //Namespace : namespace is names block 


   int x = 22; 
 
  //" :: " can also be used without block name to refer to a global variable

  cout << "::x : " << ::x << endl; 
 
  cout << "x : " << x << endl;

  //" :: " is called the scope resolution operator  
  cout << "Block1::xb1 = " << Block1::xb1 << endl;
  cout << "Block2::xb1 = " << Block2::xb2 << endl;
  cout << "Block3::Block3_1::xb3_1 = "<< Block3::Block3_1::xb3_1<<endl;

  //If there is no conflict in names , scope resolution prefixes (e.g. Block1, Block2 ) can be avoided by means of using declaration and directives. 

  using namespace Block1;
  {
  cout << xb1 << endl ;
  }
  using namespace Block3;
  {
    cout << Block3_1::xb3_1 << endl;
  }
}
