#include <iostream>
#include "rc_mod.h"

//#define _USE_MATH_DEFINES

using namespace std; 

int rc_mod::addNumbers( std::string targ, double theta, double xin, double& sig, double& rce){
  

  double tdiff_min, tdiff_max;
  double thetatab, tdiff, thetadeg, thetalow, thetahigh;
 
  double radcon;
 
  radcon = 180./M_PI;
  thetadeg = theta*radcon;
  //thcentdeg = thspect*radcon;



// /////////////////////////////////////
// /////READING RAD_CORR.DAT FILE //////
// /////////////////////////////////////

  double c1, c2, c3, c4, c5  ; 
  std::vector<double> column1, column2, column3, column4, column5;
  
// ifstream infile1("../input/rad_corr/externals_2017_h2_21.dat");

   ifstream infile1;  

  if(targ == "h"){
    infile1.open("../input/rad_corr/21degh2cryo18_Dave.dat");
  }else if( targ == "c"){
    infile1.open("../input/rad_corr/21degcarbon18_Dave.dat");
  }else if(targ == "d"){
    infile1.open("../input/rad_corr/21degd2cryo18_Dave.dat");
  }

  

   if(infile1.fail()){
     cout << "Cannot open the rad_corr.dat file" << endl ; 
     exit(1);
   }else{
     while(!infile1.eof()){
       

       infile1 >> c1 >> c2  >> c3 >> c4 >> c5 ;

       // infile1 >> c1 >> c2  >> c3 >> c4 >> c5 >> c6 >> c7 >> c8 >> c9 >> c10 >> c11 >> c12 >> c13; 
       
       column1.push_back(c1);
       column2.push_back(c2);
       column3.push_back(c3);
       column4.push_back(c4);
       column5.push_back(c5);
       // double w2_table = 0;
       // w2_table = mp2 + (2.0* mp * (c1-c2)) -c5;
       // cout << mp2 << " "<< mp <<" "<<(c1-c2)<<" "<<c5 <<" "<< w2_table<< endl; 
       // column1.push_back(c1);
       // column2.push_back(w2_table);
       // column3.push_back(c3);
       // column4.push_back(c6);
       // column5.push_back(c6 / c9);
       
       
       
     }
   }
   column1.pop_back();
   column2.pop_back();
   column3.pop_back();
   column4.pop_back();
   column5.pop_back();

   Int_t eentries = column1.size();

   //  cout <<"eentries : " <<eentries << endl; 

  
   ////////////////////////////////////////////////////////////
   ///////////    FIND thetalow AND thetahigh     /////////////
   ////////////////////////////////////////////////////////////

     tdiff_min = 10.0;
     tdiff_max = 10.0;
     // cout << "tdiff_min = " << tdiff_min << "tdiff_max = " << tdiff_max << endl;
     for(int j = 0; j<eentries ;j++){ // eentries loop start 
       thetatab = column3[j];
       tdiff = abs(thetatab - thetadeg);
       // cout << "thetatab=" << thetatab << endl;
       // cout << "tdiff = " << tdiff << endl;
       if(thetatab <= thetadeg){ // if 1 start 
	 if(tdiff <= tdiff_min){
	   tdiff_min = tdiff;
	   thetalow = thetatab;
	 }
       }else{
	 
	 if(tdiff <= tdiff_max){
	   tdiff_max = tdiff;
	   thetahigh = thetatab;
	 }
       } // if 1 end
     }// eentries loop end
 
     // cout << "theta =" << thetadeg << endl;
     //cout << "thetalow ="<< thetalow << endl; 
     //cout << "thetahigh ="<< thetahigh << endl; 
    
     
     ////////////////////////////////////////////////////////////
     /////////// FIND thetalow AND thetahigh START  /////////////
     ////////////////////////////////////////////////////////////

     double diffxh1 = 1000.;
     double diffxl1 = 1000.;
     double diffxl2 = 1000.;
     double diffxh2 = 1000.;

     double x[6], m[6], rc[6];


     for(int j = 0; j<eentries ;j++){ // eentries loop start 

       thetatab = column3[j];
       //cout <<"thetatab = " << thetatab << endl; 
       //cout << "theta low = " << thetalow << endl; 
       if((thetatab) == thetalow){ //if loop a start //***
	 // cout << int(thetatab) << endl;
	 if(column2[j]<xin){
	   if(abs(column2[j]-xin)<=diffxl1){
	     diffxl1=abs(column2[j]-xin);
	     x[1]=column2[j];
	     m[1]=column4[j];
	     rc[1]=column5[j];
	     //cout <<"x[1] test =" << x[1] << endl;
	   }
	 }else{
	   if(column2[j]>xin){
	     //cout << "GT" << endl;
	     if(abs(column2[j]-xin)<=diffxh1){
	       diffxh1=abs(column2[j]-xin);
	       x[2]=column2[j];
	       m[2]=column4[j];
	       rc[2]=column5[j];
	     }
	   }
	 }
       }// if loop a ends 


       if((thetatab) == thetahigh){ //if loop b start //***                                           
         // cout << int(thetatab) << endl;                                                         
         if(column2[j]<xin){
           if(abs(column2[j]-xin)<=diffxl2){
             diffxl2=abs(column2[j]-xin);
             x[3]=column2[j];
             m[3]=column4[j];
             rc[3]=column5[j];
           }
         }else{
           if(column2[j]>xin){
             //cout << "GT" << endl;                                                               
             if(abs(column2[j]-xin)<=diffxh2){
               diffxh2=abs(column2[j]-xin);
               x[4]=column2[j];
               m[4]=column4[j];
               rc[4]=column5[j];
             }
           }
         }
       }// if loop b ends                                                                          
     }//eentries loop end                           


     m[5] = ( (m[2]*(xin-x[1])) + (m[1]*(x[2]-xin)) ) / (x[2]-x[1]);
     rc[5] = ( (rc[2]*(xin-x[1])) + (rc[1]*(x[2]-xin)) ) / (x[2]-x[1]);
     m[6] = ( (m[4]*(xin-x[3])) + (m[3]*(x[4]-xin)) ) / (x[4]-x[3]);
     rc[6] = ( (rc[4]*(xin-x[3])) + (rc[3]*(x[4]-xin)) ) / (x[4]-x[3]);

     sig = (m[6] * (thetadeg-thetalow)+m[5]*(thetahigh-thetadeg) ) /(thetahigh-thetalow);
     rce = (rc[6] * (thetadeg-thetalow)+rc[5]*(thetahigh-thetadeg) ) /(thetahigh-thetalow);


     // cout << "TEST" << endl;
     // cout <<"theta low = " << thetalow << endl;


     // cout <<"x[1] = " << x[1] <<" x[2] = " << x[2] << endl;
     // cout <<"m[1] = " << m[1] <<" m[2] = " << m[2] << endl;
     // cout <<"rc[1] = " << rc[1] <<" rc[2] = " << rc[2] << endl;

     // cout <<"thetahigh " << thetahigh << endl;

     // cout <<"x[3] = " << x[3] <<" x[4] = " << x[4] << endl;
     // cout <<"m[3] = " << m[3] <<" m[4] = " << m[4] << endl;
     // cout <<"rc[3] = " << rc[3] <<" rc[4] = " << rc[4] << endl;

     // cout << "sig = " << sig << ", rce = " << rce << endl;

     return 0;
}
