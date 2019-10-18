#include "ElementaryParticle.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

int main()
{
	srand (time(NULL));
	ElementaryParticle *ep1, *ep2, *ep3;
	
	/*ep1.ime="higgsov bozon";
	ep1.masa=3.6;
	ep1.bozon=true;

	ep2.ime="kvark";
	ep2.masa=3.2;
	ep2.bozon=false;

	ep1.printinfo();
	ep2.printinfo();*/
	
	ep1 = new ElementaryParticle("z bozon", 3.4, true);
	ep2 = new ElementaryParticle();
	ep3 = new ElementaryParticle();
	ep1->printinfo();
	ep1->Unos(2.2, 3.4, 88);
	//cout<<ep1->Trans_Mom<<endl;
	ep1->bosonDecay(ep2,ep3);
	cout<<ep2->ime<<endl;


/*ElementaryParticle *ep1;

ep1->ime="z bozon";
ep1->masa=3;

ep1->printinfo();*/



 return 0;
}

