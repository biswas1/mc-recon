//chapter 3 
// while loop , do - while loop , for loop 
//example 3.18 - 3.20 

#include <iostream>

#include <cmath>

#include <iomanip>

using namespace std;

int main(){
  
  /*
  // each input from a key board has its corresponding binary equivalent(ascii code)
  // int(d) -> takes the binary equivalent and convert it into decimal(65) and send it to out put stream through cout .

  char d = 'A';
  cout << int(d) << endl; 
  cout << int('a') << endl;c
  char c =' ';

  // \n : new line is a sentinel here 

  while(c!='\n') // this is new line (i.e. 'enter' or 'return' from key board)
    {cin.get(c); // consider spaces ("c d e" reads as -> "c d e")
      //cin >> c ; // do not consider spaces ("c d e" reads as -> "cde")
      
      if(c >= 'a' && c<= 'z') c=char(c -'a' +'A');
      //cout.put(c);
      cout << c ;
       
  }
  */
  ////////////////////////
  //// do - while loop ///
  ////////////////////////

  bool cont; 
  char ans;
  
  do
    {
      cout << "Continue ? (y/n) : ";
      cin >> ans;
      if(ans == 'Y' || ans == 'y') cont = true;
      else if(ans == 'N' || ans == 'n') cont = false; 
      else cout << "Please enter the answer in Y or n.\n";
    }while(ans!= 'y' && ans != 'Y' && ans != 'n' && ans != 'N');

  cout << cont << endl ;


  //////////////////////////////
  //// number sequence /////////
  //////////////////////////////
  //////////////////////////////
  //// example how to write  ///
  /// in row - column format ///
  //////////////////////////////
  //example 3.20

  int n; 

  cout << "Enter an integer value = " ;
  
  cin >> n ; 

  int count = 0 ; // initialization of integer count 

  do
    {if (n%2 == 0 ) n/= 2;
    else n = 3*n +1 ; 


      cout  << setw(6) << n ; // specify 6 places(columns) for each output
      ++count ;
      if( count %10 == 0) cout << endl; // when ever count is multiple of 10 go to next line , by this way we can keep 10 element (output) per line 
     }while(n > 1);

  cout <<"\n That sequence has " << count << " number of elements.\n";




  // exmaple 3.21 
  //for loop 
  // do a 1*1 + 2*2 + 3*3 + .... until 100

  int m, sum ;

  for (int m =0  ; m <= 100 ;m++){

    sum += m*m ; 
    
  }
  cout << " sum = " << sum << endl ;
}
