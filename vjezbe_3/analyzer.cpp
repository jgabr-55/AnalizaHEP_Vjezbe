#include "ElementaryParticle.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

int main()
{
	srand (time(NULL));
	ElementaryParticle *ep1, *ep2, *ep3, *decayParticle_1, *decayParticle_2, *Higgs;
	
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
	ep1->Unos(2.2, 3.4, 4.6);
	//cout<<ep1->Trans_Mom<<endl;
	ep1->bosonDecay(ep2,ep3);
	cout<<ep1->px<<" "<<ep2->px<<" "<<ep3->px<<endl;*/
	Higgs->Unos(3,4,5);

	decayParticle_1 = new ElementaryParticle();
	decayParticle_2 = new ElementaryParticle();

	Higgs->bosonDecay(decayParticle_1, decayParticle_2);
	//cout<<Higgs->ime<<endl;

	cout<<"Prva cestica je: "<<decayParticle_1->ime<<", a druga: "<<decayParticle_2->ime<<endl;

	cout<<"Za prvu cesticu je px = "<<decayParticle_1->px<<", py = "<<decayParticle_1->py<<", pz = "<<decayParticle_1->pz<<endl;

	cout<<"Za drugu cesticu je px = "<<decayParticle_2->px<<", py = "<<decayParticle_2->py<<", pz = "<<decayParticle_2->pz<<endl;
	

/*ElementaryParticle *ep1;

ep1->ime="z bozon";
ep1->masa=3;

ep1->printinfo();*/



 return 0;
}

