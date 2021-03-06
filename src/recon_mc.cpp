#include <iostream>
#include "rc_mod.h"
#include <string>
#include <math.h>
#include <TCanvas.h>
 
using namespace std;

int main(){ //main loop : Start
  
 
  ofstream scale_factor;

  //////////////////////////////////////
  ///////targ boil slope ///////////////
  //////////////////////////////////////

  double targ_boil_h = -0.00049;
  double targ_boil_d = -0.0003068;
  
  //////////////////////////////////////
  /// for input file name formats //////
  //////////////////////////////////////
  

  string targ;
  cout <<"targ = c/h/d" << endl;
  cin >> targ;

  string spec;
  cout << "spectrometer (hms/shms) = " << endl;
  cin >> spec; 

  string spec_id;
  if(spec == "hms"){
    spec_id = "h";
  }else if(spec =="shms"){
    spec_id = "p";
  }

  int ang;
  cout << "ang =" << endl;
  cin >> ang;

  double mom;
  cout << "mom =" << endl;
  cin >> mom;

  int mom_int ;
  cout << "mom_int =" << endl;
  cin >> mom_int;

  int mom_dec;
  cout << "mom_dec =" << endl;
  cin >> mom_dec;

  cout <<"mom = " << mom << " ,mom_int = "<< (mom-mom_int) << " ,mom_dec = " << mom_dec << endl; ;



  ////////////////////////////////////
    //// set up interpolation class ////
    ////////////////////////////////////


      TGraph2D *dtsig = new TGraph2D();
      TGraph2D *dtrci = new TGraph2D();
      
      std::ifstream rc_file;
      
      if(ang == 8){
	rc_file.open(Form("/w/hallc-scifs17exp/inclusive/abels/MC/tables/%s_%s10.6_all.dat_inel_f1f220_9_8",spec.c_str(),targ.c_str())); // 8 degree f1f220 produced by Abel
      }else{
	rc_file.open(Form("/w/hallc-scifs17exp/inclusive/abels/MC/tables/%s_%s10.6_all.dat_inel_f1f220",spec.c_str(),targ.c_str())); // f1f220 produced by Abel

      }

      // if(targ == "h"){
      // 	//rc_file.open("../input/rad_corr/21degh2cryo18_Dave.dat");
      // 	rc_file.open(Form("/w/hallc-scifs17exp/inclusive/abels/MC/tables/%s_%s10.6_all.dat_inel_f1f220",spec.c_str(),targ.c_str())); // f1f220 produced by Abel
      // }else if(targ == "c"){
      // 	//rc_file.open("../input/rad_corr/21degcarbon18_Dave.dat");
      // 	rc_file.open("/w/hallc-scifs17exp/inclusive/abels/MC/tables/shms_c10.6_all.dat_inel_f1f220");
      // }else if(targ == "d"){
      // 	//rc_file.open("../input/rad_corr/21degd2cryo18_Dave.dat");
      // 	rc_file.open("/w/hallc-scifs17exp/inclusive/abels/MC/tables/shms_d10.6_all.dat_inel_f1f220");
      // }

      while(true){
	Double_t x[5];
	rc_file>>x[0]>>x[1]>>x[2]>>x[3]>>x[4];
	if(rc_file.eof())break;
	Int_t dtNsig=dtsig->GetN();
	//cout << "dtNsig = " << dtNsig << endl;
	//cout << x[1] <<" " << x[2]<<" "<<x[3]<< endl;
	dtsig->SetPoint(dtNsig,x[1],x[2],x[3]);
	Int_t dtNrci=dtrci->GetN();
	dtrci->SetPoint(dtNrci,x[1],x[2],x[4]);
      }
      TCanvas *c1 = new TCanvas("c1","c1",800,900);
      c1->cd();
      dtsig->Draw("surf1");
      c1->SaveAs("c1.png");
      cout <<"inter = " << dtrci->TGraph2D::Interpolate(6.9,21.2) << endl;

///////////////////////////////////////

  const double mp = 0.9382723;
  const double mp2 = mp * mp ;
  const double e_charge = 1.60217662e-19; //unit: columb 
  const double avogardo_number = 6.022137e23; //mol^-1

  cout << "e charge = "<< e_charge << endl;

  double  rce;
  rc_mod obj1;

  double born;
  double born1, rce1;

  bool cryo = true; 
  
  
  //double radcon = 180./3.141592654;
  double radcon = 180./TMath::Pi();

   
    /////////////////////////////////////////
    //// READ UNIFORMLY GENERATED MC ////////
    /////////////////////////////////////////
    
 

  // TFile *f = new TFile(Form("../input/monte-carlo/shms_%ddeg_m%dp%d.root",ang,mom_int,mom_dec),"READ"); 
  //  TFile *f = new TFile("../input/monte-carlo/c21_3.3.root"); 
  TFile *f;
  if(spec == "hms" && mom == 1.05){
    f = new TFile(Form("/w/hallc-scifs17exp/xem2/biswas/cross-section-code/mc-single-arm/worksim/%s_%ddeg_m%dp0%d_%s.root",spec.c_str(),ang, mom_int, mom_dec,targ.c_str()),"READ"); 
  }else{
    f = new TFile(Form("/w/hallc-scifs17exp/xem2/biswas/cross-section-code/mc-single-arm/worksim/%s_%ddeg_m%dp%d_%s_yo.root",spec.c_str(),ang, mom_int, mom_dec,targ.c_str()),"READ");
    // f = new TFile(Form("/w/hallc-scifs17exp/xem2/aruni/mc-single-arm-new/mc-single-arm/worksim/%s_%ddeg_carbon_aruni.root",spec.c_str(),ang),"READ");
    
  }

  // TFile *f = new TFile("/w/hallc-scifs17exp/inclusive/abels/MC/mc-single-arm/worksim/h39_1.3.root","READ");
 
  cout <<"worksim file = " << f << endl;

  TTree *T;
  
  if(spec=="shms"){
    T = (TTree*)f->Get("h1411");
  }else{
    T = (TTree*)f->Get("h1");
  }


  int totev = T->GetEntries();
  
  float x_fp, y_fp, delta, deltai, xptar, yptar, xptari, yptari, stop_id, xp_fp, yp_fp, xtar, ytar;
  
  double sin2, hse, nu, q2, w2, w, xb; // these are cal for the born and ph sp
  double sin2_rc, hse_rc, nu_rc, q2_rc, w2_rc, w_rc, xb_rc; // these are calculated for data/mc comparison

  // NOTE : do not use the branches ends with i , i stands for initial, 
  // i.e. uniformly generated Monte Carlo events 

  
  T->SetBranchAddress("stop_id",&stop_id);
  T->SetBranchAddress(Form("%ssxfp",spec_id.c_str()),&x_fp); 
  T->SetBranchAddress(Form("%ssyfp",spec_id.c_str()),&y_fp);
  T->SetBranchAddress(Form("%ssxpfp",spec_id.c_str()),&xp_fp); 
  T->SetBranchAddress(Form("%ssypfp",spec_id.c_str()),&yp_fp); 
  T->SetBranchAddress(Form("%ssdelta",spec_id.c_str()),&delta);
  // T->SetBranchAddress("psxtar",&xtar);
  T->SetBranchAddress(Form("%ssytar",spec_id.c_str()),&ytar);
  T->SetBranchAddress(Form("%ssxptar",spec_id.c_str()),&xptar);
  T->SetBranchAddress(Form("%ssyptar",spec_id.c_str()),&yptar);
  T->SetBranchAddress(Form("%ssyptari",spec_id.c_str()),&yptari);
  T->SetBranchAddress(Form("%ssxptari",spec_id.c_str()),&xptari);
  T->SetBranchAddress(Form("%ssdeltai",spec_id.c_str()),&deltai);
  

  double sigave = 0.0;
  int ngen = 0;


  ///////////////////////////////
  ////Reading input.dat file/////
  ///////////////////////////////
  std::string infile;
  int       maxev, cs_flag, rc_flag; 
  double    dxp, dyp, delup, deldown; 
  double    targetdata[6];
  
 // ifstream infile2("../../mc-reweight/input/recon-mc/kpp_shms_488_input.dat");
 //../input/recon-mc/recon.in
  ifstream infile2(Form("../input/recon-mc/input_%s.dat",spec.c_str()));
 std::string str;  
 
 if(infile2.fail()){
   std::cout << "Cannot open the input.in file: " << std::endl;
   exit(1);
   
 }else{
   while(!infile2.eof()){
     
     infile2 >> infile >>  maxev >> dxp >> dyp >> delup >> deldown >> cs_flag >> rc_flag ; 
     
    }
 }
 
 cout << "recon_mc : " << infile <<" "<< maxev<<" " << dxp<<" " << dyp<<" " << delup<<" " << deldown<<" " << cs_flag<<" " <<rc_flag << endl;


  /////////////////////////////////////
  //////Reading the reconmc.in/////////
  /////////////////////////////////////
  
  
  
  std::vector<int> run_num, target;
  int r1, r2; 

  std::vector<double>    ebeam,hsec,thetac,prescale,bcm1_cur,bcm2_cur,bcm1charge,bcm2charge,cltime,eltime,trackeff,trigeff,rate, column16, column17; 
  double r3, r4, r5,r6, r7, r8, r9, r10, r11, r12, r13, r14, r15, r16, r17;    
  string recon;
  if(spec == "hms" && mom == 1.05){
    recon = (Form("../input/recon-mc/%s_recon_ang_%d_m%dp0%d_%s.in",spec.c_str(),ang,mom_int,mom_dec,targ.c_str()));
  }else{
    recon = (Form("../input/recon-mc/%s_recon_ang_%d_m%dp%d_%s.in",spec.c_str(),ang,mom_int,mom_dec,targ.c_str()));
  } 
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
      if(spec=="shms"){
	hsec.push_back(r4-(0.017*r4));
	//hsec.push_back(r4);
      }else if(spec=="hms"){
	if(mom == 5.7){
	  hsec.push_back(r4);
	}else{
	  hsec.push_back(r4*((-0.000276*r4*r4*r4) + (0.002585*r4*r4) -(0.008697*r4) +1.0064));
	}
      }
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
  cout << "tot_run = " << tot_run << endl;

  //////////////////////////////////////////
  //////// Initialize Radcor Arrays ////////
  //////////////////////////////////////////
  

 std::vector<double> bcmavecharge ; 
 std::vector<double> dep;
 std::vector<double> phase_space;
 std::vector<double> lumdata;
 double fract[tot_run]; 
 double fract1[tot_run];

  TFile *f_W_MC[tot_run];

  for(int i=0; i<tot_run ; i++){ // loop B starts 

   if(spec == "hms" && mom == 1.05){
     f_W_MC[i] = new TFile(Form("/w/hallc-scifs17exp/xem2/biswas/cross-section-code/mc-recon-c-incubator/output/%s_fwmc_ang_%d_m%dp0%d_%s_f1f220rc.root",spec.c_str(),ang,mom_int,mom_dec,targ.c_str()),"RECREATE");
   }else{
     f_W_MC[i] = new TFile(Form("/w/hallc-scifs17exp/xem2/biswas/cross-section-code/mc-recon-c-incubator/output/%s_fwmc_ang_%d_m%dp%d_%s_f1f220rc_yo.root",spec.c_str(),ang,mom_int,mom_dec,targ.c_str()),"RECREATE"); //point, aruni
   }
    TTree *re_weighted = new TTree("re_weighted","re weighted");
    
    double xptar_i, yptar_i;
    double delta_rw, xfp_rw, yfp_rw, xpfp_rw, ypfp_rw, w2_rw, q2_rw, stop_id_rw;
    double born_rw, rce_rw, phsp_rw;
    
    re_weighted->Branch("xptar_i",&xptar_i, "xptar_i/D");
    re_weighted->Branch("yptar_i",&yptar_i, "yptar_i/D");
    re_weighted->Branch("xfp_rw",&xfp_rw, "xfp_rw/D");
    re_weighted->Branch("yfp_rw",&yfp_rw, "yfp_rw/D");
    re_weighted->Branch("xpfp_rw",&xpfp_rw, "xpfp_rw/D");
    re_weighted->Branch("ypfp_rw",&ypfp_rw, "ypfp_rw/D");
    re_weighted->Branch("w2_rw",&w2_rw, "w2_rw/D");
    re_weighted->Branch("q2_rw",&q2_rw, "q2_rw/D");
    re_weighted->Branch("delta_rw",&delta_rw, "delta_rw/D");
    re_weighted->Branch("stop_id_rw",&stop_id_rw, "stop_id_rw/D");
    re_weighted->Branch("born_rw",&born_rw, "born_rw/D");
    re_weighted->Branch("rce_rw",&rce_rw, "rce_rw/D");
    re_weighted->Branch("phsp_rw",&phsp_rw, "phsp_rw/D");

    //////////////////////////////
    ///// average bcm charge /////
    //////////////////////////////
    
    
    
    bcmavecharge.push_back(bcm2charge[i]);  // average beam charge : if we use 2 bcms 
    cout <<"average charge = " << bcmavecharge[i] << endl;  
    
    
    //////////////////////////////
    //// calculate dep ///////////
    //////////////////////////////
    
    
    dep.push_back(((delup-deldown)*hsec[i])/100.);
    
    
    /////////////////////////////////
    //// phase space calculation ////
    /////////////////////////////////
    
    phase_space.push_back((4.0 * dxp * dyp * dep[i]) / 1000.0) ;
   
    
    cout <<"dep = " << dep[i]<<" ,phase sp = " << phase_space[i] << endl; 
    
    
    ////////////////////////////////////////////////////////
    //////////// READ TARGET DATA FROM FILE ////////////////
    ////////////////////////////////////////////////////////
    
    ifstream infile3("../input/target/targetdata_2017.dat");
    
    double t1, t2, t3, t4, t5;
    
    if(infile3.fail()){
      cout << "Cannot open the targetdata.dat file: " << endl;
      exit(1);
      
    }else{
      // while(!infile3.eof()){
      for(int j =0; j<target[i]; j++){
	
	infile3 >> targetdata[0] >>  targetdata[1] >> targetdata[2] >> targetdata[3] >> targetdata[4] >> targetdata[5] ; 
	
      }
    }  
    // cout << targetdata[0] << endl;
    // NOTE : targetdata[5] : target density, targetdata[3] : Atomic Mass
    
    cout << targetdata[0] <<" "<<  targetdata[1] <<" "<< targetdata[2] <<" "<< targetdata[3] <<" "<< targetdata[4] <<" "<< targetdata[5] << endl;
    
    
    //////////////////////////////////
    //// calculate luminosity ////////
    //////////////////////////////////
    
    
    
    //0.996 : target length contraction correction 
    lumdata.push_back((targetdata[1] * targetdata[2]* 0.996* 6.022137e-10 * (1/targetdata[3]))*(bcmavecharge[i]/1.602177e-13));

    cout <<"bcmavecharge[i] = " << bcmavecharge[i]<< endl;
    cout <<"targetdata[5] = " << targetdata[5] << endl;
    cout <<"targetdata[3] = "<<targetdata[3] << endl;
    cout <<"targetdata[2] = "<<targetdata[2] << endl;
    cout <<"lumdata = " << lumdata[i] << endl;

  

    for(int k=0; k< 1000000 ; k++){ // event loop A start //aruni
      
      T->GetEntry(k);
      
      //cout << "event number =" << k << endl;
      
      ////////////////////////////////////////////
      /////// CALCULATE VERTEX KINEMATICS  ///////
      /////// for Born and radiative corr  ///////
      /////// with the initial quantitites ///////
      ///////  and phase space correction  ///////
      ////////////////////////////////////////////
   
      double thetai;
      
      if(spec == "hms"){
	thetai = (acos(cos((thetac[i]/radcon) - yptari)*cos(xptari)));
	//thetai = (acos(cos((thetac[i]/radcon) - yptar)*cos(xptar)));
      }else if(spec == "shms"){
	thetai = (acos(cos((thetac[i]/radcon) + yptari)*cos(xptari)));
	//thetai = (acos(cos((thetac[i]/radcon) + yptar)*cos(xptar)));
      }

      sin2 = sin(thetai/2.0)*sin(thetai/2.0);
      hse  = hsec[i] * (1+(deltai/100.0));
      //hse  = hsec[i] * (1+(delta/100.0));
      //hse  = hsec[i] * (1+(delta/100.0));
      nu   = ebeam[i] - hse;
      q2   = 4*hse*ebeam[i]*sin2; 
      w2   = mp2 + (2.0 * mp * nu ) - q2;
      w    = sqrt(w2);
      xb   = q2 / (2.0 * mp * nu); 
      
     
      // cout << "thetac ="<< thetac[i] << endl;
      //cout << "thetai = " << thetai << endl;
      double dt = thetai - (thetac[i]/radcon);
      // double phasespcor = 1.0/pow(cos(dt),3); // old formula 
      double phasespcor = 1.0/pow((1+(xptari*xptari)+(yptari*yptari)),1.5);
      //cout << "w2 = " << w2 << endl;
      

      // if(nu <0.015 && w2 < 0.84){
	//	born = 0;
	//  }else{
	//obj1.addNumbers(targ, thetai, w2, born , rce);
	//obj1.addNumbers(targ, thetai, w2, born1 , rce1);
	
	born  = dtsig->TGraph2D::Interpolate(w2, (thetai*radcon));
	//cout <<"w2 = " << w2 << " theta = "<< (thetai*radcon) << endl;
	//cout <<"born = " << born <<" born1 = " << born1 << endl;
	rce   = dtrci->TGraph2D::Interpolate(w2,(thetai*radcon));
	//cout <<"rce = " << rce <<" rce1 = " << rce1 << endl; 
	// }
	//cout <<"ph sp cor = " << phasespcor << endl;



	

        if((abs(xptari) < dxp) && (abs(yptari) < dyp) && (deltai > deldown) && (deltai < delup) && (born >= 0) ){
	//if((abs(xptari) < dxp) && (abs(yptari) < dyp) && (deltai > deldown)  && (deltai < delup) ){
	sigave = sigave + born;
	ngen = ngen + 1;
	
	}



      ////////////////////////////////////////////
      /////// CALCULATE VERTEX KINEMATICS  ///////
      /////// for data/mc compariosn with  ///////
      /////// the reconstructed quantities ///////
      ////////////////////////////////////////////
   
      double theta_rc; //rc stands for: calculated with reconstructed quantitites
      
      if(spec == "hms"){
	theta_rc = (acos(cos((thetac[i]/radcon) - yptar)*cos(xptar)));
      }else if(spec == "shms"){
	theta_rc = (acos(cos((thetac[i]/radcon) + yptar)*cos(xptar)));
      }

      sin2_rc = sin(theta_rc/2.0)*sin(theta_rc/2.0);
      hse_rc  = hsec[i] * (1+(delta/100.0));
      nu_rc   = ebeam[i] - hse_rc;
      q2_rc   = 4*hse_rc*ebeam[i]*sin2_rc; 
      w2_rc   = mp2 + (2.0 * mp * nu_rc ) - q2_rc;
      w_rc    = sqrt(w2_rc);
      xb_rc   = q2_rc / (2.0 * mp * nu_rc);

      
      xptar_i    = xptari;
      yptar_i    = yptari;  
      delta_rw   = delta ;
      xfp_rw     = xtar ;
      yfp_rw     = ytar;
      xpfp_rw    = xptar ;
      ypfp_rw    = yptar ;
      w2_rw      = w2_rc ;
      q2_rw      = q2_rc ;
      stop_id_rw = stop_id ;
      born_rw    = born ;
      rce_rw     = rce ;
      phsp_rw    = phasespcor;
     
      re_weighted->Fill();
      

    }//event loop A ends
    
 
  



  ///////////////////////////////////
  ///// write a new root file ///////
  /////  for the weighted MC  ///////
  ///////////////////////////////////

 
  f_W_MC[i]->Write();
  f_W_MC[i]->Close();
 

 

  
  //////////////////////////
  //// mc scale factor /////
  //////////////////////////

  cout << "ngen = " << ngen << endl;
 
  /////////////////////////
  // cerenkov efficiency //
  ///////////////////////// 
  double eff_cer = 1.0; 
 

  ////////////////////////////
  // calorimeter efficiency //
  //////////////////////////// 
  double eff_cal = 1.0;
 

  //////////////////////////
  //// targ boil corr //////
  //////////////////////////

  double targ_boil = 0.0;
  if(targ == "c"){
     targ_boil = 1.0 ;
  }else if(targ == "h"){
    // targ_boil = (1 + targ_boil_h * bcm2_cur[i]);
    targ_boil = 1.0;
  }else if(targ == "d"){
    // targ_boil = (1 + targ_boil_d * bcm2_cur[i]);
    targ_boil = 1.0;
  }
  
  cout <<" targ boil = " << targ_boil <<" at current "<< bcm2_cur[i] << "uA" << endl;

  //////////////////////////
  //fract : mc scale factor//
  ///////////////////////////

  fract1[i] =  (lumdata[i] * phase_space[i])/(ngen * 1000.0) ;
  fract[i]  = (fract1[i]* trackeff[i] * trigeff[i] * cltime[i] * eff_cer * eff_cal * targ_boil) / prescale[i] ;
 

  cout << "fract = " << fract[i] << endl ;
 
  if(spec == "hms" && mom == 1.05){
    scale_factor.open(Form("../output/%s_scale_factor_ang_%d_m%dp0%d_%s_f1f220rc.txt",spec.c_str(),ang, mom_int,mom_dec,targ.c_str()));  
  }else{
    scale_factor.open(Form("../output/%s_scale_factor_ang_%d_m%dp%d_%s_f1f220rc_yo.txt",spec.c_str(),ang, mom_int,mom_dec,targ.c_str())); // point, aruni
  }
  scale_factor << run_num[i] <<" "<< ngen <<" "<< fract[i] <<" "<< endl;
  
  }//tot_run loop B ends 
  
  scale_factor.close();
  
  return 0;
} //main loop : End
