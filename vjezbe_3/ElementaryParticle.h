#include <iostream>

using namespace std;

class ElementaryParticle{
 public:
	string ime;
	double masa;
	bool bozon;

	void printinfo();	

	ElementaryParticle(string name,double mass,bool boson);

	double px,py,pz,E,Trans_Mom;

	void Unos(double a, double b, double c);
	void TransMoment();
};
