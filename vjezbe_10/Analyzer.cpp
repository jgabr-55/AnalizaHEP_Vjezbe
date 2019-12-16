#define Analyzer_cxx
#include "Analyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TLine.h>

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
   likelihood->SetParameter(0,0.1);
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

double tau_hat,sigma_m,sigma_p,tau_hat1,sigma_m1,sigma_p1;
tau_hat=1.0/chi_s->GetMinimumX();
sigma_m=tau_hat-1.0/(chi_s->GetX(chi_s->GetMinimum()+1.0,1.0,tau_hat-0.01));
sigma_p=1.0/(chi_s->GetX(chi_s->GetMinimum()+1.0,tau_hat,10.0))-tau_hat;

//cout<<"dsads"<<tau_hat<<endl;
cout<<sigma_m<<endl;
cout<<sigma_p<<endl;

tau_hat1=chi_s->GetMinimumX();
sigma_m1=tau_hat1-chi_s->GetX(chi_s->GetMinimum()+1.0,1.0,tau_hat1-0.01);
sigma_p1=chi_s->GetX(chi_s->GetMinimum()+1.0,tau_hat1,10.0)-tau_hat1;


c1->cd(2);

chi_s->Draw();
c1->Update();
TLine *l1 = new TLine(1./tau_hat,1.95,1./tau_hat,chi_s->GetMinimum());
TLine *l2 = new TLine(tau_hat1-sigma_m1,1.95,tau_hat1-sigma_m1,chi_s->GetMinimum()+1.0);
TLine *l3 = new TLine(tau_hat1-sigma_p1,1.95,tau_hat1-sigma_p1,chi_s->GetMinimum()+1.0);
l1->Draw("same");
l2->Draw("same");
l3->Draw("same");

 c1->SaveAs("opca_1.png");

   double theta,br=0.0,naz=0.0, greska=0.0, pod_kor=0.0,pod_kv=0.0;
   
	for(int i = 0; i<5;i++)
	{
		br=br+(2.0*x[i]*y[i])/(ey[i]*ey[i]);
		naz=naz+(2.0*x[i]*x[i])/(ey[i]*ey[i]);
	}

	theta = br/naz;

	for(int i = 0; i<5;i++)
	{
		pod_kor=pod_kor+((y[i]-theta*x[i])*(y[i]-theta*x[i]))/(ey[i]*ey[i]);
		pod_kv=pod_kv+(2.0*theta*x[i]*x[i]-2.0*x[i]*y[i])/(ey[i]*ey[i]);
	}

	greska=0.5*TMath::Power(pod_kor,-0.5)*naz - 0.25*TMath::Power(pod_kor,-1.5)*TMath::Power(pod_kv,2);
	
	
	cout<<1.0/theta<<" +- "<<1.0/greska<<endl;
}
