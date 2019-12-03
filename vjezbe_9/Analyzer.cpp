#define Analyzer_cxx
#include "Analyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TF1.h>

void Analyzer::Loop()
{
	TCanvas *c = new TCanvas("c","c");
	c->Divide(3,1);
	TH1F *t1= new TH1F("mjerenje","",20,0,10);

	TF1 *pdf = new TF1("PDF","(1.0/[0])*TMath::Exp((-1/[0])*x)*[1]",0,10);
	TF1 *likelihood = new TF1("likelihood","([0]/x)*TMath::Exp((-[1]/x))",0,10);
	pdf->SetParameters(5,300);
	likelihood->SetParameters(1,1);

	double tau=0.0;
	double sigma_m, sigma_p,tau_hat;

//   In a ROOT session, you can do:
//      root> .L Analyzer.C
//      root> Analyzer t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

	tau=tau+t;
	

	t1->Fill(t);
   }
TF1 *log_likelihood = new TF1("log_likelihood","-2000*TMath::Log(1.0/x)+(2.0/x)*[0]",1.15,1.40);
log_likelihood->SetParameter(0,tau);
tau_hat=log_likelihood->GetMinimumX();
sigma_m=tau_hat-log_likelihood->GetX(log_likelihood->GetMinimum()+1.0,1.0,tau_hat-0.01);
sigma_p=log_likelihood->GetX(log_likelihood->GetMinimum()+1.0,tau_hat,10.0)-tau_hat;

cout<<sigma_m<<endl;
cout<<sigma_p<<endl;

cout<<"Procjenjena vrijednost za tau je: "<<tau/1000.0<<endl;
cout<<log_likelihood->GetMinimumX()<<endl;
cout<<tau/TMath::Sqrt(1000*1000*1000)<<endl;
c->cd(1);
   t1->Draw();
   t1->Fit(pdf);
   gStyle->SetOptFit();
   c->cd(2);
   likelihood->Draw();
   c->cd(3);
   log_likelihood->Draw();
   //t1->Fit(likelihood);
   gStyle->SetOptFit();
	
   c->SaveAs("histo_mjerenje.png");
}
