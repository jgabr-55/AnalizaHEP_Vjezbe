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

ElementaryParticle::ElementaryParticle()
	{
		ime = "";
		masa = 0.0;
		bozon = false;		
	}


void ElementaryParticle::bosonDecay(ElementaryParticle * c1, ElementaryParticle * c2)
	{
		double r = rand()%100;
		if(bozon == false)
			cout<<"Raspad nije moguć"<<endl;
		else
		{
		if(r<21.4 && r>6.4)
			{ c1->ime = "W";
			  c1->masa = 80.39;
			  c1->bozon = true;
			  c2->ime = "W";
			  c2->masa = 80.39;
			  c2->bozon = true;
			  
			}
		if(r<6.4 && r>2.6)
			{ c1->ime = "tau";
			  c1->masa = 1.776;
			  c1->bozon = true;
			  c2->ime = "tau";
			  c2->masa = 1.776;
			  c2->bozon = true;	
			}
		if(r<2.6 && r>0.0)
			{ c1->ime = "Z";
			  c1->masa = 91.19;
			  c1->bozon = true;
			  c2->ime = "Z";
			  c2->masa = 91.19;
			  c2->bozon = true;	
			}
		else
			{ c1->ime = "b kvark";
			  c1->masa = 4.180;
			  c1->bozon = false;
			  c2->ime = "b kvark";
			  c2->masa = 4.180;
			  c2->bozon = false;	
			}
		//p=sqrt(px*px+py*py+pz*pz);
	        r = rand() % int(0.7*px)+0.3*px;
		c1->px = r;
		c2->px = px-r;
		
		r = rand() % int(0.7*py)+0.3*py;
		c1->py = r;
		c2->py = py-r;

		r = rand() % int(0.7*pz)+0.3*pz;
		c1->pz = r;
		c2->pz = pz-r;
		
		}
	}

		
		
