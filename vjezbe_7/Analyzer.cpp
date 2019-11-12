#define Analyzer_cxx
#include "Analyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <THStack.h>

void Analyzer::Loop(TString fileName)
{
	
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/home/public/data/"+fileName+"/ZZ4lAnalysis.root"); 
      if (!f || !f->IsOpen()) {
         f = new TFile("/home/public/data/"+fileName+"/ZZ4lAnalysis.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("/home/public/data/"+fileName+"/ZZ4lAnalysis.root:/ZZTree");
      dir->GetObject("candTree",tree);
	
      weight_histo = (TH1F*)f->Get("/home/public/data/"+fileName+"/ZZ4lAnalysis.root:/ZZTree/Counters");

   	
   	Init(tree);

	TCanvas *c = new TCanvas("c","c",1800,1800); // brojevi se odnose na dimenzije slike
	c->Divide(2,2); //broj stupaca, broj redaka

	//TCanvas *c1 = new TCanvas("c1","c1",900,900);

	
	

	TH1F *h1_trans_mom = new TH1F("trans_mom_leptona","",100,0,100); //brojevi se odnose na binove , pa granice.
	TH1F *h2_trans_mom = new TH1F("","",100,0,100);
	TH1F *h3_trans_mom = new TH1F("","",100,0,100);
	TH1F *h4_trans_mom = new TH1F("","",100,0,100);

	TH1F *h1_pseudorap = new TH1F("pseudorapiditet","",100,-3,3); //brojevi se odnose na binove i sl.
	TH1F *h2_pseudorap = new TH1F("","",100,-3,3);
	TH1F *h3_pseudorap = new TH1F("","",100,-3,3);
	TH1F *h4_pseudorap = new TH1F("","",100,-3,3);

	TH1F *h1_azim_kut = new TH1F("azimutalni_kut","",100,-5,5); //brojevi se odnose na binove i sl.
	TH1F *h2_azim_kut = new TH1F("","",100,-5,5);
	TH1F *h3_azim_kut = new TH1F("","",100,-5,5);
	TH1F *h4_azim_kut = new TH1F("","",100,-5,5);

	TH1F *h1_bdt = new TH1F("BDT_rezultat","",100,-10,10); //brojevi se odnose na binove i sl.
	TH1F *h2_bdt = new TH1F("","",100,-10,10);
	TH1F *h3_bdt = new TH1F("","",100,-10,10);
	TH1F *h4_bdt = new TH1F("","",100,-10,10);

	
	
	
	
	

	

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

	double omega = (137*1000*xsec*overallEventWeight)/(weight_histo->GetBinContent(40));
	

	h1_trans_mom->Fill(LepPt->at(0),omega); //histogram ("ono cime ga punimo na x os")
	h2_trans_mom->Fill(LepPt->at(1),omega);
	h3_trans_mom->Fill(LepPt->at(2),omega);
	h4_trans_mom->Fill(LepPt->at(3),omega);

	h1_pseudorap->Fill(LepEta->at(0),omega);
	h2_pseudorap->Fill(LepEta->at(1),omega);
	h3_pseudorap->Fill(LepEta->at(2),omega);
	h4_pseudorap->Fill(LepEta->at(3),omega);

	h1_azim_kut->Fill(LepPhi->at(0),omega);
	h2_azim_kut->Fill(LepPhi->at(1),omega);
	h3_azim_kut->Fill(LepPhi->at(2),omega);
	h4_azim_kut->Fill(LepPhi->at(3),omega);

	h1_bdt->Fill(LepBDT->at(0),omega);
	h2_bdt->Fill(LepBDT->at(1),omega);
	h3_bdt->Fill(LepBDT->at(2),omega);
	h4_bdt->Fill(LepBDT->at(3),omega);

	l1.SetPtEtaPhiM(LepPt->at(0), LepEta->at(0), LepPhi->at(0), 0);
	l2.SetPtEtaPhiM(LepPt->at(1), LepEta->at(1), LepPhi->at(1), 0);
	l3.SetPtEtaPhiM(LepPt->at(2), LepEta->at(2), LepPhi->at(2), 0);
	l4.SetPtEtaPhiM(LepPt->at(3), LepEta->at(3), LepPhi->at(3), 0);

	z1 = l1 + l2;
	z2=l3+l4;

	h=z1+z2;

	D=1/(1+(70*p_QQB_BKG_MCFM)/p_GG_SIG_ghg2_1_ghz1_1_JHUGen);
	
	if(fileName=="ggH125")
		{
			h5_higgs->Fill(h.M(),omega);
			h6_kin_diskr_sig->Fill(D,omega);
			masa_kin_sig->Fill(h.M(),D,omega);
		}
	else{
		h5_qqzz->Fill(h.M(),omega);
		h6_kin_diskr_poz->Fill(D,omega);
		}

   }

	
	c->cd(1);
	h1_trans_mom->GetXaxis()->SetTitle("Transverzalni moment");
	h1_trans_mom->GetYaxis()->SetTitle("Broj pojavljivanja");
	h1_trans_mom->SetLineColor(1);
	h2_trans_mom->SetLineColor(2);
	h3_trans_mom->SetLineColor(209);
	h4_trans_mom->SetLineColor(62);

	h1_trans_mom->Draw("hist");
	h2_trans_mom->Draw("SAME" "hist");
	h3_trans_mom->Draw("SAME" "hist");
	h4_trans_mom->Draw("SAME" "hist");

	c->cd(2);
	h1_pseudorap->GetXaxis()->SetTitle("Pseudorapiditet");
	h1_pseudorap->GetYaxis()->SetTitle("Broj pojavljivanja");
	


	h1_pseudorap->SetLineColor(1);
	h2_pseudorap->SetLineColor(2);
	h3_pseudorap->SetLineColor(209);
	h4_pseudorap->SetLineColor(62);

	h1_pseudorap->Draw("hist");
	h2_pseudorap->Draw("SAME" "hist");
	h3_pseudorap->Draw("SAME" "hist");
	h4_pseudorap->Draw("SAME" "hist");

	c->cd(3);
	h1_azim_kut->GetXaxis()->SetTitle("Azimutalni kut");
	h1_azim_kut->GetYaxis()->SetTitle("Broj pojavljivanja");
	


	h1_azim_kut->SetLineColor(1);
	h2_azim_kut->SetLineColor(2);
	h3_azim_kut->SetLineColor(209);
	h4_azim_kut->SetLineColor(62);

	h1_azim_kut->Draw("hist");
	h2_azim_kut->Draw("SAME" "hist");
	h3_azim_kut->Draw("SAME" "hist");
	h4_azim_kut->Draw("SAME" "hist");

	c->cd(4);
	h1_bdt->GetXaxis()->SetTitle("BDT");
	h1_bdt->GetYaxis()->SetTitle("Broj pojavljivanja");
	


	h1_bdt->SetLineColor(1);
	h2_bdt->SetLineColor(2);
	h3_bdt->SetLineColor(209);
	h4_bdt->SetLineColor(62);

	h1_bdt->Draw("hist");
	h2_bdt->Draw("SAME" "hist");
	h3_bdt->Draw("SAME" "hist");
	h4_bdt->Draw("SAME" "hist");

	c->cd(1);
TLegend *legend1 = new TLegend(0.5,0.8,0.7,0.9);

legend1->AddEntry(h1_trans_mom,"Lep_1","l");
legend1->AddEntry(h2_trans_mom,"Lep_2","l");
legend1->AddEntry(h3_trans_mom,"Lep_3","l");
legend1->AddEntry(h4_trans_mom,"Lep_4","l");
legend1->Draw();

c->cd(2);
TLegend *legend2 = new TLegend(0.1,0.8,0.3,0.9);

legend2->AddEntry(h1_pseudorap,"Lep_1","l");
legend2->AddEntry(h2_pseudorap,"Lep_2","l");
legend2->AddEntry(h3_pseudorap,"Lep_3","l");
legend2->AddEntry(h4_pseudorap,"Lep_4","l");
legend2->Draw();

c->cd(3);
TLegend *legend3 = new TLegend(0.1,0.8,0.2,0.9);

legend3->AddEntry(h1_azim_kut,"Lep_1","l");
legend3->AddEntry(h2_azim_kut,"Lep_2","l");
legend3->AddEntry(h3_azim_kut,"Lep_3","l");
legend3->AddEntry(h4_azim_kut,"Lep_4","l");
legend3->Draw();

c->cd(4);
TLegend *legend4 = new TLegend(0.1,0.8,0.3,0.9);

legend4->AddEntry(h1_bdt,"Lep_1","l");
legend4->AddEntry(h2_bdt,"Lep_2","l");
legend4->AddEntry(h3_bdt,"Lep_3","l");
legend4->AddEntry(h4_bdt,"Lep_4","l");
legend4->Draw();



//c->SaveAs("histo.pdf")
//c->SaveAs("histo.png");
//c->SaveAs("histo.root");

h5_higgs->SetFillColor(kRed);
h5_qqzz->SetFillColor(kBlue);

//h5_higgs->Draw("hist");
 // za zad 1 triba crtat one 4 komponente za leptone a ne ovo 

	
}

void Analyzer::PlotMass()
{
TCanvas *c1 = new TCanvas("c1","c1",900,900);

THStack *hs = new THStack("hs","");

//cout<<h5_higgs->Integral()<<endl;

/*hs->Add(h5_qqzz);
hs->Add(h5_higgs);

hs->Draw("hist");
c1->SaveAs("_histo.png");*/ // za zad 1 triba crtat one 4 komponente za leptone a ne ovo 

masa_kin_sig->Draw("colz");

c1->SaveAs("2d.png");


}

void Analyzer::PlotD()
{
	TCanvas *c1 = new TCanvas("c1","c1",900,900);
	
	h6_kin_diskr_sig->SetLineColor(kBlue);
	h6_kin_diskr_poz->SetLineColor(kRed);

	h6_kin_diskr_sig->Scale(1/h6_kin_diskr_sig->Integral());
	h6_kin_diskr_poz->Scale(1/h6_kin_diskr_poz->Integral());

	h6_kin_diskr_sig->Draw("hist");
	h6_kin_diskr_poz->Draw("SAME hist");

	c1->SaveAs("kin_diskr.png");
}




