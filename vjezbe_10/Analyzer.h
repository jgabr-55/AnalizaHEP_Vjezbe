//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Dec  3 10:20:28 2019 by ROOT version 6.18/04
// from TTree Tree/Lifetime decay data
// found on file: /home/public/data/Lifetime/Lifetime.root
//////////////////////////////////////////////////////////


#include<iostream>

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TGraphErrors.h>

using namespace std;


// Header file for the classes stored in the TTree if any.

class Analyzer {
public :
   
   virtual void     Fit();

private:

   TCanvas *c1;
   TGraphErrors *gr;
   TF1 *likelihood, *chi_s;
   
};





