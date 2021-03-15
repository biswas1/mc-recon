#include <iostream>
#include <string>
#include <math.h>
#include "rc_mod.h"

using namespace std;

int main(){ // main loop starts  

 
 


/// for input file name formats ///////
  string targ = "c";
  int ang =21;
  double mom = 3.3;
  int mom_int =  floor(mom) ; // returning the largest integral value which is not greater than x 
  // int mom_dec = int(10.0 * (mom - mom_int)); //10.0 is hard coded here NOT GOOD
  int mom_dec = 3; 
  cout << "mom_dec = " << mom_dec << endl; 


  ///////////////////////////////////////////
  //////////// READ recon.in file ///////////
  ///////////////////////////////////////////
  


 std::vector<int> run_num, target;
  int r1, r2; 

  std::vector<double>    ebeam,hsec,thetac,prescale,bcm1_cur,bcm2_cur,bcm1charge,bcm2charge,cltime,eltime,trackeff,trigeff,rate, column16, column17; 
  double r3, r4, r5,r6, r7, r8, r9, r10, r11, r12, r13, r14, r15, r16, r17;    
 
  string recon = (Form("../input/recon-mc/recon_ang_%d_m%dp%d_%s.in",ang,mom_int,mom_dec,targ.c_str()));
  cout << "recon.in = " << recon << endl;
  ifstream infile1(recon.c_str());
  
  if(infile1.fail()){
    cout << "Cannot open the reconmc.in file: " << endl;
    exit(1);
    
  }else{
    while(!infile1.eof()){
      infile1 >> r1 >> r2 >> r3 >> r4 >> r5 >> r6 >> r7 >>r8 >> r9 >> r10 >> r11 >> r12 >> r13 >> r14 >> r15 >> r16 >> r17;
      
      run_num.push_back(r1);
      target.push_back(r2);
      ebeam.push_back(r3);
      hsec.push_back(r4);
      thetac.push_back(r5);
      prescale.push_back(r6);
      bcm1_cur.push_back(r7);
      bcm2_cur.push_back(r8);
      bcm1charge.push_back(r9);
      bcm2charge.push_back(r10);
      cltime.push_back(r11);
      eltime.push_back(r12);
      trackeff.push_back(r13);
      trigeff.push_back(r14);
      rate.push_back(r15);
      column16.push_back(r16);
      column17.push_back(r17);
      
    }
  }

  run_num.pop_back();
  target.pop_back();
  ebeam.pop_back();
  hsec.pop_back();
  thetac.pop_back();
  prescale.pop_back();
  bcm1_cur.pop_back();
  bcm2_cur.pop_back();
  bcm1charge.pop_back();
  bcm2charge.pop_back();
  cltime.pop_back();
  eltime.pop_back();
  trackeff.pop_back();
  trigeff.pop_back();
  rate.pop_back();
  column16.pop_back();
  column17.pop_back();
  
  int tot_run = run_num.size(); 
  cout << "run = " << run_num[0] << "tot_run = " << tot_run << endl;


  ////////////////////////////////////////////
  ////// Draw the histograms for yields //////
  ////////////////////////////////////////////
  
  TH1F *delta_d[tot_run];
  TH1F *delta_mc[tot_run];


  TImage *img[tot_run];

  ////////////////////////////
  //// LOOP over all the /////
  ////    all the runs   /////
  ////////////////////////////
 
  for(int i=0; i<tot_run; i++){


    delta_d[i] = new TH1F(Form("delta_d_%d",run_num[i]),Form(" delta data",run_num[i]),100.0, -20., 25.);
    delta_mc[i] = new TH1F(Form("delta_mc_%d",run_num[i]),Form(" delta MC %d",run_num[i]),100.0, -20., 25.);
    
    int yield_mc=0;
    int yield_data=0;
    
    ///////////////////////////////////////////
    ///// READ THE REWEIGHTED ROOT FILE ///////
    ///////////////////////////////////////////
    
    TFile *f = new TFile(Form("/w/hallc-scifs17exp/xem2/biswas/cross-section-code/mc-recon-c-incubator/output/fwmc_%d.root",run_num[i]),"READ");

    TTree *T = (TTree*)f->Get("re_weighted"); 

    Int_t totev = T->GetEntries();

    double delta;
   

    T->SetBranchAddress("delta_rw",&delta);

    for (Int_t j=0 ; j<totev; j++){
      T->GetEntry(j);
      yield_mc ++;
      delta_mc[i]->Fill(delta);
    }
    


    ///////////////////////////////////////////
    ///// READ THE DATA ROOT FILE /////////////
    ///////////////////////////////////////////
  

    TFile *f_data = new TFile(Form("/lustre19/expphy/cache/hallc/E12-10-002/abishek/realpass-3-shms-data/shms_replay_production_%d_-1.root",run_num[i]),"READ");
    
    TTree *T_data = (TTree*)f_data->Get("T"); 
    
    Int_t totev_data = T_data->GetEntries();
    
    double etracknorm_data, dp_data, beta_data;
    double npe_data, bcm4c_data; 
    double delta_data;
    
    T_data->SetBranchAddress("P.gtr.dp",&delta_data);
    T_data->SetBranchAddress("P.ngcer.npeSum",&npe_data);
    T_data->SetBranchAddress("P.cal.etracknorm",&etracknorm_data);
    T_data->SetBranchAddress("P.gtr.beta",&beta_data);
    // T_data->SetBranchAddress("ibcm4a",&bcm4a_data);
    T_data->SetBranchAddress("P.bcm.bcm4c.AvgCurrent",&bcm4c_data);

    for (Int_t j=0 ; j<totev_data; j++){
      T_data->GetEntry(j);
      // if(npe_data > 1.0 && etracknorm_data > 0.7 && beta_data > 0.5 && beta_data < 1.5 && dp_data < 22. && dp_data > -10.){
      if(npe_data > 1.0 && etracknorm_data > 0.7 && beta_data > 0.5 && beta_data < 1.5 && delta_data < 22. && delta_data > -10. && bcm4c_data > 5.0){
      yield_data ++;
      delta_d[i]->Fill(delta_data);
      // cout <<" delta = "  << delta_data <<  endl;
	 }
    }  

    TCanvas *c1 = new TCanvas("c1" , "delta MC", 800, 900);
    c1->Divide(2,2);
    //c1->cd(1);
    // delta_mc[i]->Draw();
    c1->cd(2);
    delta_d[i]->Draw();

    cout << " Run Number = " << run_num[i] << endl; 
    cout << " DATA YIELD : "<< yield_data << endl;
    cout << " BCM4C charge = " << bcm2charge[i] << endl; 
    cout << " charge normalized yield =" << (yield_data / bcm2charge[i] ) << endl;
    cout << " cltime = "<< cltime[i] << " trk eff = "<< trackeff[i] << " prescale = "<< prescale[i] << endl;
    cout << "effi cor nor yield =" <<(prescale[i]*yield_data)/(bcm2charge[i]*cltime[i]*trackeff[i]) <<endl; 

    img[i] = TImage::Create();
    img[i]->FromPad(c1);
    img[i]->WriteImage(Form("../output/delta_data_%d.png",run_num[i]));

    // double bincontent = delta_d->GetBinContent(100);
    //cout << "bin content = " << bincontent << endl;
  }

  
  /////////////////////////////////////////////////////
  rc_mod obj1;
  double born, rce;
  double theta = 0.4; 
  double w2 = 14.45; 
  obj1.addNumbers(targ,theta, w2, born, rce);
  cout << "rce = "<< rce <<" ,sig =  " << born << endl;
  cout <<" test 1 " << endl; 
  ////////////////////////////////////////////////////


  return 0;

} // main loop ends 
