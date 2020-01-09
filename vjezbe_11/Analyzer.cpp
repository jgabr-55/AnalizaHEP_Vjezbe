#include <Analyzer.h>
#include <fstream>
#include <sstream>
#include <string>
#include <TROOT.h>
#include <TChain.h>
#include <TStyle.h>
#include <TFile.h>
#include <TApplication.h>
#include <inttypes.h>
#include <TH2F.h>
#include <TH1F.h>
#include <TCanvas.h>

double Analyzer::Binomna(int r, double p, int N)
{
	double bin = (Fakt(N)/(Fakt(r)*Fakt(N-r)))*TMath::Power(p,r)*TMath::Power((1-p),(N-r));
	return bin;
}

long int Analyzer::Fakt(int broj)
{
	long int i = 1;
	if(broj!=0){
	for(int j=1;j<=broj;j++)
		i=i*j;
	return i;}
	else
		return 1;
}

double Analyzer::CP_upper(int r, int N, double conf_lvl)
{
	double step_size=0.001;
	double sum=0.0;
	bool pr=true;
	
	while(pr==true)
	{
	/*if(step_size==0.003)
		break;*/
	for(int i=r+1;i<=N;i++)
	{
		sum=sum+Binomna(i,step_size,N);
		//cout<<sum<<endl;
		
		
	}
	
	if(sum>1-((1-conf_lvl)/2))
	{
		return step_size;
		pr=false;
	}
	else
	{
		sum=0.0;
		step_size=step_size+0.001;
	}
}
}

double Analyzer::CP_lower(int r, int N, double conf_lvl)
{
	double step_size=1.00;
	double sum=0.0;
	bool pr=true;
	
	while(pr==true)
	{
	/*if(step_size==0.003)
		break;*/
	for(int i=0;i<=r-1;i++)
	{
		sum=sum+Binomna(i,step_size,N);
		//cout<<sum<<endl;
		
		
	}
	
	if(sum>1-((1-conf_lvl)/2))
	{
		return step_size;
		pr=false;
	}
	else
	{
		sum=0.0;
		step_size=step_size-0.001;
	}
}
}

void Analyzer::ClopperPearson(int N, double CL)
{

TCanvas *c = new TCanvas("c","c",800,800);
TH1F *lower = new TH1F("cp_lower","",10,1,11);
TH1F *upper = new TH1F("cp_upper","",10,1,11);




	for(int r=1;r<=N-1;r++)
		{
			cout<<"CP = ["<<CP_lower(r,N,CL)<<", "<<CP_upper(r,N,CL)<<"]"<<endl;
			lower->SetBinContent(r,CP_lower(r,N,CL));
			upper->SetBinContent(r,CP_upper(r,N,CL));
		}

c->cd(1);
lower->SetStats(0);
upper->SetStats(0);

lower->SetMaximum(1.0);
upper->SetMaximum(1.0);


lower->Draw();
upper->Draw("same");


c->SaveAs("CP_pojas.png");

}


	

