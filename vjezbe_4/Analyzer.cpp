#include <Analyzer.h>
#include <fstream>
#include <sstream>
#include <string>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TApplication.h>
#include <inttypes.h>

void Analyzer::ReadFile()
{
	
	ifstream myReadFile;
  	myReadFile.open ("Analysis.txt");

	string line;

	if(myReadFile.is_open()) 
	{
		while(getline(myReadFile, line))
		{
			stringstream linestream(line);

			linestream >> _EventNumber >> _DecayParticle1_name >> _DecayParticle1_isBoson >> _DecayParticle1_mass >> _DecayParticle1_px >> _DecayParticle1_py >> _DecayParticle1_pz >> _DecayParticle1_E >> _DecayParticle1_pt >> _DecayParticle2_name >> _DecayParticle2_isBoson >> _DecayParticle2_mass >> _DecayParticle2_px >> _DecayParticle2_py >> _DecayParticle2_pz >> _DecayParticle2_E >> _DecayParticle2_pt;
}}

myReadFile.close();

}

void Analyzer::ConvertTxtToRootFile()
{
	
	ifstream myReadFile;
  	myReadFile.open ("Analysis.txt");

	TFile *tree = new TFile("Analysis.root", "RECREATE");

	TTree *T = new TTree("T","stablo");

	
	
	/*Int_t EventNumber;
	Char_t _DecayParticle1_name,_DecayParticle2_name;
	Bool_t _DecayParticle1_isBoson,_DecayParticle2_isBoson;
	Double_t _DecayParticle1_mass,_DecayParticle1_px,_DecayParticle1_py,_DecayParticle1_pz,_DecayParticle1_E,_DecayParticle1_pt;
	Double_t _DecayParticle2_mass,_DecayParticle2_px,_DecayParticle2_py,_DecayParticle2_pz,_DecayParticle2_E,_DecayParticle2_pt;*/

	T->Branch("EventNumber", &_EventNumber,"_EventNumber/I");
	T->Branch("Particle1name", &_DecayParticle1_name,"_DecayParticle1_name/B");
	T->Branch("Particle1isBoson", &_DecayParticle1_isBoson,"_DecayParticle1_isBoson/O");
	T->Branch("Particle1mass", &_DecayParticle1_mass,"_DecayParticle1_mass/D");
	T->Branch("Particle1px", &_DecayParticle1_px,"_DecayParticle1_px/D");
	T->Branch("Particle1py", &_DecayParticle1_py,"_DecayParticle1_py/D");
	T->Branch("Particle1pz", &_DecayParticle1_pz,"_DecayParticle1_pz/D");
	T->Branch("Particle1E", &_DecayParticle1_E,"_DecayParticle1_E/D");
	T->Branch("Particle1pt", &_DecayParticle1_pt,"_DecayParticle1_pt/D");
	
	T->Branch("Particle2name", &_DecayParticle2_name,"_DecayParticle2_name/B");
	T->Branch("Particle2isBoson", &_DecayParticle2_isBoson,"_DecayParticle2_isBoson/O");
	T->Branch("Particle2mass", &_DecayParticle2_mass,"_DecayParticle2_mass/D");
	T->Branch("Particle2px", &_DecayParticle2_px,"_DecayParticle2_px/D");
	T->Branch("Particle2py", &_DecayParticle2_py,"_DecayParticle2_py/D");
	T->Branch("Particle2pz", &_DecayParticle2_pz,"_DecayParticle2_pz/D");
	T->Branch("Particle2E", &_DecayParticle2_E,"_DecayParticle2_E/D");
	T->Branch("Particle2pt", &_DecayParticle2_pt,"_DecayParticle2_pt/D");

	string line;

	if(myReadFile.is_open()) 
	{
		while(getline(myReadFile, line))
		{
			stringstream linestream(line);

			linestream >> _EventNumber >> _DecayParticle1_name >> _DecayParticle1_isBoson >> _DecayParticle1_mass >> _DecayParticle1_px >> _DecayParticle1_py >> _DecayParticle1_pz >> _DecayParticle1_E >> _DecayParticle1_pt >> _DecayParticle2_name >> _DecayParticle2_isBoson >> _DecayParticle2_mass >> _DecayParticle2_px >> _DecayParticle2_py >> _DecayParticle2_pz >> _DecayParticle2_E >> _DecayParticle2_pt;

T->Fill();
}}

myReadFile.close();
tree->Write();
}

	
	

	

