#ifndef rc_mod_H
#define rc_mod_H

#include <iostream>
#include <fstream>
#include "TROOT.h"
#include <string>
#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"
#include "TF1.h"
#include "TGraph.h"
#include "TGraph2D.h"
#include <TROOT.h>
#include <iomanip>
#include "TMath.h"
#include "TGraphDelaunay.h"
#include "Math/Interpolator.h"
#include "Math/Polynomial.h"

using namespace std;

class rc_mod
{

 public:
  
  int addNumbers( string targ, double theta,double xin,  double& sig, double& rce);
  
};



  /*  
public:
  double addNumbers(bool firstr, double theta, double thspect, double xin, int tarid);

  

 double thetadeg, thcentdeg, thspect, thetatab, tdiff;
 double thetalow, thetahigh; 
 double xin; 
 int tarid; 
 double x[6], rc[6], m[6];
 double rce, sig; 

 int tdiff_min = 10.0;
 int tdiff_max = 10.0;

 bool extrap_x_lo = true;
 bool extrap_x_hi = true;
 double diffxH1 = 1000.0;
 double diffxL1 = 1000.0;
 double diffxH2 = 1000.0;
 double diffxL2 = 1000.0;

 

};
*/

#endif
