#include"Student.h"

int main(int argc, char *argv[]){


 

  TFile *f = new TFile("/lustre/expphy/volatile/hallc/xem2/biswas/ROOTfiles/shms_replay_production_all_2484_10000.root"); 
  TTree *T = (TTree*)f->Get("T");

  int totev = T->GetEntries();

  std::cout << "TOT EVENTS : " << T->GetEntries() << std::endl; 
  std::cout << " test " << std::endl; 

  for(int i =0; i<totev; i++){
    std::cout << i << std::endl; 
   
  } 

  Student s("joe");
  s.display();


  return 0;

}
//  /lustre/expphy/volatile/hallc/xem2/biswas/ROOTfiles/shms_replay_production_all_2484_19.root
