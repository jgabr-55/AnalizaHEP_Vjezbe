#define Analyzer_cxx
#include "Analyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLegend.h>

void Analyzer::Loop()
{
	TCanvas *c = new TCanvas("c","c",3700,900); // brojevi se odnose na dimenzije slike
	c->Divide(3,0); //broj stupaca, broj redaka

	TH1F *histo_ele_pt = new TH1F("transverzalni_moment_elektrona","",100,0,100); 
	histo_ele_pt->SetLineColor(2);
	histo_ele_pt->GetXaxis()->SetTitle("transverzalni moment elektrona");
	histo_ele_pt->GetYaxis()->SetTitle("broj pojavljivanja");
	
	TH2F *histo_zad2_b = new TH2F("scl_eta_vs_ele_pt","",100,0,100,30,-3,3);

	TH1F *histo_ele_ep = new TH1F("ele_ep","",30,0,10);
	TH1F *histo_ele_eelepout = new TH1F("ele_eelepout","",30,0,10);

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
   for (Long64_t jentry=0; jentry<100000;jentry++) { //nentries
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
	histo_ele_pt->Fill(ele_pt);
	histo_zad2_b->Fill(ele_pt,scl_eta);
	histo_ele_ep->Fill(ele_ep);
	histo_ele_eelepout->Fill(ele_eelepout);
	
   }
    c->cd(1);
	gStyle->SetOptStat(0);
	histo_ele_pt->Draw();
    c->cd(2);
	histo_zad2_b->GetXaxis()->SetTitle("ele_pt");
	histo_zad2_b->GetYaxis()->SetTitle("scl_eta");
	histo_zad2_b->Draw("colz");
    c->cd(3);
	histo_ele_ep->Scale(1/histo_ele_pt->Integral());
	histo_ele_eelepout->Scale(1/histo_ele_eelepout->Integral());

	histo_ele_ep->SetLineColor(2);
	histo_ele_ep->SetLineStyle(2);

	histo_ele_eelepout->SetFillColor(4);

	histo_ele_ep->Draw("hist");
	histo_ele_eelepout->Draw("hist same");

	TLegend *legend1 = new TLegend(0.5,0.8,0.7,0.9);

	legend1->AddEntry(histo_ele_ep,"ele_ep","l");
	legend1->AddEntry(histo_ele_eelepout,"ele_eelepout","f");
	
	legend1->Draw();
	

    c->SaveAs("histo_el_pt.png");
}
