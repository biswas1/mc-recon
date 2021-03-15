//chapter 3 - control structure 
//example 3.22 - 3.25

#include <iomanip>

#include <iostream>

#include <cmath>


int main(){
  // The continue statement  // example - 3.22
  int n = 7; 

  for (int k = 50 ; k<75; k++)//    < -----
                              //          | brings the control back to condition
                              //          | to check whether next teration or no
    {if (k%n == 0 ) continue; //----------- 

std::cout << k << " " ; 

    }
  std::cout << std::endl; 

  // if n is multiple of k goes back to loop condition 
  // otherwise cout k

  // The break Statement // example - 3.23
 int n1 = 7; 

  for (int k1 = 50 ; k1<75; k1++)
                              
                              
    {if (k1%n1 == 0 ) break;    //----------- 
                                //          | not only skips the remainder of
      std::cout << k1 << " " ;  //          | the current iteration, also ter-
                                //          | minate loop
    }                           //          |
  std::cout << "out of the loop" << std::endl; // <------


  // example 3.24 // controlling an infinite while loop 

  int n2 = 4; 

  while(true) // condition is just 'ture' ! interesting , it simply means go inside the loop 
              // and do the job , 'false ' do not go into the loop 
    {
std::cout << 1.0 / n2 << "\t";
      if ( n2 == 9 ) break;
      ++n2;
    }
std::cout << "\n" << n << std::endl; 
  


//example 3.25 Controlling a "forever" loop
// for(;;) is equivalent to while(true)

int product = 1, factor, count = 0; 

std::cout << "enter factor . To terminate put factor 0." ;

for (;;){

std::cin >> factor;

if(factor == 0 )break; 

product *= factor;



++count;

}

std::cout <<"The product of the " << count << " factor is " << product << std::endl; 





}
