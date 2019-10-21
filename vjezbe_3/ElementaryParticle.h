#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class ElementaryParticle{
 public:
	string ime;
	double masa;
	bool bozon;

	void printinfo();	

	ElementaryParticle(string name,double mass,bool boson);

	double px,py,pz,E,Trans_Mom,p;

	void CetveroVektor(double a, double b, double c);
	double TransMoment();

	ElementaryParticle();
	
	void bosonDecay(ElementaryParticle *a, ElementaryParticle *b);
};
