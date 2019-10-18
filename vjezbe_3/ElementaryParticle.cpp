#include "ElementaryParticle.h"
#include <cmath>

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

void ElementaryParticle::Unos(double a, double b, double c)
	{
		px=a;
		py=b;
		pz=c;
		E=sqrt(px*px+py*py+pz*pz+masa*masa);
	}

void ElementaryParticle::TransMoment()
	{
		Trans_Mom = sqrt (px*px+py*py);
		cout<<"Transverzalni moment je: "<<Trans_Mom<<endl;
	}
		
