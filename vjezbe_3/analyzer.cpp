#include "ElementaryParticle.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <fstream> 

int main()
{
	srand (time(NULL));
	ElementaryParticle *ep1,*ep2,*ep3,*decayParticle_1, *decayParticle_2, *Higgs;
	
	
	/*ep1.ime="higgsov bozon";
	ep1.masa=3.6;
	ep1.bozon=true;

	ep2.ime="kvark";
	ep2.masa=3.2;
	ep2.bozon=false;

	ep1.printinfo();
	ep2.printinfo();*/
	
	Higgs = new ElementaryParticle("Higgs bozon", 125.09, true);
	/*ep2 = new ElementaryParticle();
	ep3 = new ElementaryParticle();
	ep1->printinfo();
	ep1->Cetverovektor(2.2, 3.4, 4.6);
	//cout<<ep1->Trans_Mom<<endl;
	ep1->bosonDecay(ep2,ep3);
	cout<<ep1->px<<" "<<ep2->px<<" "<<ep3->px<<endl;*/
//zad_2
	/*Higgs->Cetverovektor(3,4,5);

	decayParticle_1 = new ElementaryParticle();
	decayParticle_2 = new ElementaryParticle();

	Higgs->bosonDecay(decayParticle_1, decayParticle_2);
	//cout<<Higgs->ime<<endl;

	cout<<"Prva cestica je: "<<decayParticle_1->ime<<", a druga: "<<decayParticle_2->ime<<endl;

	cout<<"Za prvu cesticu je px = "<<decayParticle_1->px<<", py = "<<decayParticle_1->py<<", pz = "<<decayParticle_1->pz<<endl;

	cout<<"Za drugu cesticu je px = "<<decayParticle_2->px<<", py = "<<decayParticle_2->py<<", pz = "<<decayParticle_2->pz<<endl;*/
	
//zad_3
	int n=10000;
	ElementaryParticle *Higgsovi = new ElementaryParticle[n];
	
	ep2 = new ElementaryParticle();
	ep3 = new ElementaryParticle();
	double cetverov_pom[3];
	
	ofstream myfile;
  	myfile.open ("Analysis.txt");

	 myfile << "EventNumber DecayParticle1_Name DecayParticle1_isBoson DecayParticle1_mass DecayParticle1_px DecayParticle1_py DecayParticle1_pz DecayParticle1_E DecayParticle1_pt" <<
                       " DecayParticle2_Name DecayParticle2_isBoson DecayParticle2_mass DecayParticle2_px DecayParticle2_py DecayParticle2_pz DecayParticle2_E DecayParticle2_pt" << endl;

	for(int i = 0;i < n; i++)
		{
			Higgsovi[i]=ElementaryParticle("Higgs boson", 125.09, true);
			for(int j=0; j<3; j++)
				{
					cetverov_pom[j]=(rand() % 200) - 100;
				}
			
			Higgsovi[i].CetveroVektor(cetverov_pom[0],cetverov_pom[1],cetverov_pom[2]);
			//cout<<Higgsovi[i].px<<"\t"<<Higgsovi[i].py<<"\t"<<Higgsovi[i].pz<<endl;
			Higgsovi[i].bosonDecay(ep2,ep3);
			
			//myfile<<ep2->ime<<endl;
			
			/*myfile.write((char*)&ep2, sizeof(ep2)); 
			myfile.write((char*)&ep3, sizeof(ep3)); */
			myfile << i << " " << ep2->ime << " "<< ep2->bozon << " " << ep2->masa << " "
                             << ep2->px << " " << ep2->py << " " << ep2->pz << " " << ep2->E << " " << ep2->TransMoment() << " "
                             << ep3->ime << " "<< ep3->bozon << " " << ep3->masa << " "
                             << ep3->px << " " << ep3->py << " " << ep3->pz << " " << ep3->E << " " << ep3->TransMoment() << endl;

			
			
		}
	
	
	myfile.close();

	
	

/*ElementaryParticle *ep1;

ep1->ime="z bozon";
ep1->masa=3;

ep1->printinfo();*/



 return 0;
}

