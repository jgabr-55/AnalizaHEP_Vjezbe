#define Analyzer_cxx
#include "Analyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TF1.h>

void Analyzer::Fit()
{
   c1 = new TCanvas("c1","A Simple Graph with error bars",200,10,700,500);
c1->Divide(1,2);
c1->cd(1);
   const Int_t n = 5;
   Double_t x[n]  = {1.0,2.0,3.0,4.0,5.0};
   Double_t y[n]  = {9.8,21.2,34.5,39.9,48.5};
   Double_t ex[n] = {0.0,0.0,0.0,0.0,0.0};
   Double_t ey[n] = {1.0,1.9,3.1,3.9,5.1};
   gr = new TGraphErrors(n,x,y,ex,ey);
   gr->SetTitle("TGraphErrors Example");
   gr->SetMarkerColor(4);
   gr->SetMarkerStyle(21);
   gr->Draw("AP");

   TF1 *likelihood = new TF1("fit_likelihood","x/[0]",0,6);
   likelihood->SetParameter(0,1.0);
   gStyle->SetOptFit();
   gr->Fit(likelihood);
  
TF1 *chi_s = new TF1("chi_sq","TMath::Power(([0]-x*[1]),2)/([2]*[2])+TMath::Power(([3]-x*[4]),2)/([5]*[5])+TMath::Power(([6]-x*[7]),2)/([8]*[8])+TMath::Power(([9]-x*[10]),2)/([11]*[11])+TMath::Power(([12]-x*[13]),2)/([14]*[14])",9.4,11);

chi_s->SetParameter(0,y[0]);
chi_s->SetParameter(1,x[0]);
chi_s->SetParameter(2,ey[0]);
chi_s->SetParameter(3,y[1]);
chi_s->SetParameter(4,x[1]);
chi_s->SetParameter(5,ey[1]);
chi_s->SetParameter(6,y[2]);
chi_s->SetParameter(7,x[2]);
chi_s->SetParameter(8,ey[2]);
chi_s->SetParameter(9,y[3]);
chi_s->SetParameter(10,x[3]);
chi_s->SetParameter(11,ey[3]);
chi_s->SetParameter(12,y[4]);
chi_s->SetParameter(13,x[4]);
chi_s->SetParameter(14,ey[4]);




cout<<1.0/chi_s->GetMinimumX()<<endl;

  

c1->cd(2);

chi_s->Draw();

 c1->SaveAs("opca_1.png");

   /*double theta;
   
	
	
	theta = br/naz;
	cout<<1/theta<<endl;*/
}
