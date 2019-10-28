#include <iostream>
#include <string>

using namespace std;

class Analyzer{

public:
	int _EventNumber;
	string _DecayParticle1_name;
	bool _DecayParticle1_isBoson;
	double _DecayParticle1_mass;
	double _DecayParticle1_px;
	double _DecayParticle1_py;
	double _DecayParticle1_pz;
	double _DecayParticle1_E;
	double _DecayParticle1_pt;
	
	string _DecayParticle2_name;
	bool _DecayParticle2_isBoson;
	double _DecayParticle2_mass;
	double _DecayParticle2_px;
	double _DecayParticle2_py;
	double _DecayParticle2_pz;
	double _DecayParticle2_E;
	double _DecayParticle2_pt;


	void ReadFile();
	void ConvertTxtToRootFile();

	



};
