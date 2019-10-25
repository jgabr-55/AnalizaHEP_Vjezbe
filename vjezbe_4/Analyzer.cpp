#include <Analyzer.h>
#include <fstream>
#include <sstream>
#include <string>

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
