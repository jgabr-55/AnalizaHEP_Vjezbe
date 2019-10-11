#include "ElementaryParticle.h"

void ElementaryParticle::printinfo()
	{
	 cout<<"ime: "<<ime<<",masa: "<<masa<<",bozon: "<<bozon<<endl;
	}

ElementaryParticle::ElementaryParticle(string name,double mass,bool boson)
	{
		ime = name;
		masa = mass;
		bozon = boson;		
	}
