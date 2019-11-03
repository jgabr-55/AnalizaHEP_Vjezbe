#define Analyzer_cxx
#include "Analyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <THStack.h>
#include <TLorentzVector.h>

void Analyzer::Loop()


{
	//void SetHistLineColor(Color_t color = 1);

	TCanvas *c = new TCanvas("c","c",1800,900); // brojevi se odnose na dimenzije slike
	c->Divide(2,0); //broj stupaca, broj redaka
	

	TH1F *h1 = new TH1F("trans_kol_gib_1","",100,0,100); //brojevi se odnose na binove i sl.
	TH1F *h2 = new TH1F("trans_kol_gib_2","",100,0,100);
	TH1F *h3 = new TH1F("","",100,0,100);
	TLorentzVector *Higgs, *part_1, *part_2;

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
	//cout<<EventNumber<<endl;

	h1->Fill(Particle1pt); //histogram ("ono cime ga punimo na x os")
	h2->Fill(Particle2pt);
	
	//koristeći vektore dobijemo komponente kolicine gibanja za Higgsa
	part_1 = new TLorentzVector(Particle1px,Particle1py,Particle1pz,Particle1E);
	part_2 = new TLorentzVector(Particle2px,Particle2py,Particle2pz,Particle2E);
	Higgs=new TLorentzVector();

	*Higgs = *part_1 + *part_2;


	double tmp = sqrt((Higgs->Px())*(Higgs->Px())+(Higgs->Py())*(Higgs->Py())); //pt za Higgs
	h3->Fill(tmp);
   }

//h1->SetHistLineColor(Color_t color = 1);
c->cd(1);//postavljanje aktivnog prozora
h1->GetXaxis()->SetTitle("Transverzalna kolicina gibanja");
h1->GetYaxis()->SetTitle("Broj pojavljivanja");
h1->SetLineColor(2);
h1->SetFillColor(2);
h1->SetTitle("Histogram transverzalne kolicine gibanja cestica 1 i 2");

h2->SetLineColor(209);
//h2->SetFillColor(1);

h3->SetLineColor(4);
h1->Draw();
h2->Draw("SAME");
c->cd(2);

h3->SetTitle("Histogram transverzalne kolicine gibanja rekonstruiranog Higgs bozona");
h3->GetXaxis()->SetTitle("Transverzalna kolicina gibanja");
h3->GetYaxis()->SetTitle("Broj pojavljivanja");
h3->Draw("SAME");

gStyle->SetOptStat(0);



//h1->Draw(); //histogram
//h2->Draw();
/*THStack *hs = new THStack("hs","Transverzalna kol gibanja");
hs->Add(h1);
hs->Add(h2);*/

//Crtamo legendu za cestice s pt1 i pt2
c->cd(1);
TLegend *legend = new TLegend(0.1,0.8,0.3,0.9);
//legend->SetHeader("Header","C");

legend->AddEntry(h1,"Cestica1","f");
legend->AddEntry(h2,"Cestica2","l");
legend->Draw();

//crtamo legendu za rekonstruirani Higgs bozon
c->cd(2);
TLegend *legend1 = new TLegend(0.1,0.8,0.3,0.9);
legend1->AddEntry(h3,"Rekonstruirani Higgs bozon","l");
legend1->Draw();
//legend->SetTextAlign(13);

c->SaveAs("histo.pdf");
c->SaveAs("histo.png");
c->SaveAs("histo.root");

}


