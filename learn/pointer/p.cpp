#include <iostream>
using namespace std;


//function declaration 
double print_element_function();
double* print_array();




//initializing an array with elements as doubles 
//amazing an array can be declaired outside the main 
double test_array[4] = {1.0, 2.0, 3.0, 4.0};
double test_array_1[4] = {400., 200., 300., 400.};

//main function
int main(){
  
  std::cout << "test" << std::endl;
  
  //std::cout << test_array[0] << std::endl;
  
  
  //call the function declaired outside the main function 
  //No -1 :
  // std::cout << print_element_function() << std::endl;
  
  //No -2:
  double first_element = print_element_function();
  std::cout << first_element << std::endl;

  //for the function print_array()
  double* array = print_array();
  cout << "*array: "<< *array << endl; // its only show the first element ??
  cout << "array: "<< array[2] << endl; // 2nd element 
  // return 0;
  
  
}


//function definition 
//make a function wich will return the test_array[0] value 

double print_element_function(){
  // std::cout << "print the first element of the array "  << std::endl;  
  // std::cout << "first element of array : " << test_array[0] << std::endl;
  return test_array[0];
}


double* print_array(){
  // std::cout << "print the first element of the array "  << std::endl;  
  // std::cout << "first element of array : " << test_array[0] << std::endl;
  return test_array_1;
}
