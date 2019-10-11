#include <iostream>

using namespace std;

class ElementaryParticle{
 public:
	string ime;
	double masa;
	bool bozon;

	void printinfo();	

	ElementaryParticle(string name,double mass,bool boson);
	
};
