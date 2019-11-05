#define Analyzer_cxx
#include "Analyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void Analyzer::Loop()
{
	TCanvas *c = new TCanvas("c","c",1800,1800); // brojevi se odnose na dimenzije slike
	c->Divide(2,2); //broj stupaca, broj redaka

	TCanvas *c1 = new TCanvas("c1","c1",900,900);
	

	TH1F *h1 = new TH1F("trans_mom_leptona","",100,0,100); //brojevi se odnose na binove i sl.
	TH1F *h2 = new TH1F("pseudorapiditet","",100,-3,3);
	TH1F *h3 = new TH1F("azimutalni_kut","",100,-5,5);
	TH1F *h4 = new TH1F("BDT_rezultat","",100,-10,10);

	TH1F *h5 = new TH1F("Higgs","",25,90,140);

	
	

	

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

	h1->Fill(LepPt->at(0)); //histogram ("ono cime ga punimo na x os")
	h2->Fill(LepEta->at(0));
	h3->Fill(LepPhi->at(0));
	h4->Fill(LepBDT->at(0));

	l1.SetPtEtaPhiM(LepPt->at(0), LepEta->at(0), LepPhi->at(0), 0);
	l2.SetPtEtaPhiM(LepPt->at(1), LepEta->at(1), LepPhi->at(1), 0);
	l3.SetPtEtaPhiM(LepPt->at(2), LepEta->at(2), LepPhi->at(2), 0);
	l4.SetPtEtaPhiM(LepPt->at(3), LepEta->at(3), LepPhi->at(3), 0);

	z1 = l1 + l2;
	z2=l3+l4;

	h=z1+z2;

	double omega = (137*1000*xsec*overallEventWeight)/(weight_histo->GetBinContent(40));

	h5->Fill(h.M(),omega);
   }

	
	c->cd(1);
	h1->Draw();

	c->cd(2);
	h2->Draw();

	c->cd(3);
	h3->Draw();

	c->cd(4);
	h4->Draw();

c->SaveAs("histo.pdf");
c->SaveAs("histo.png");
c->SaveAs("histo.root");

c1->cd();

h5->Draw("hist");
c1->SaveAs("Higgs_histo.png");

	
}
