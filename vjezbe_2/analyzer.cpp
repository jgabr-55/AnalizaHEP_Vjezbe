#include "ElementaryParticle.h"

int main()
{
	ElementaryParticle *ep1;
	
	/*ep1.ime="higgsov bozon";
	ep1.masa=3.6;
	ep1.bozon=true;

	ep2.ime="kvark";
	ep2.masa=3.2;
	ep2.bozon=false;

	ep1.printinfo();
	ep2.printinfo();*/
	
	ep1 = new ElementaryParticle("z bozon", 3.4, true);
	ep1->printinfo();


/*ElementaryParticle *ep1;

ep1->ime="z bozon";
ep1->masa=3;

ep1->printinfo();*/



 return 0;
}

