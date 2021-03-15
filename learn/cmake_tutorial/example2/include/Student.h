#include<string>
#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"
#include "TF1.h"
#include "TGraph.h"
#include <fstream>
#include <iostream>
#include <TROOT.h>


class Student{

 private:
  std::string name;
 public:
  Student(std::string);
  virtual void display();

};
