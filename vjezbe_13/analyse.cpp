#include "Analyzer.h"

using namespace std;

int main(){

	Analyzer *a = new Analyzer();
	a->Loop();
	a->Theoretical_t_gauss();
	a->ah_test(164.7,7.1);

return 0;
}


