#include "Analyzer.h"

using namespace std;

int main(){

	Analyzer *a = new Analyzer();
	a->Loop("ggH125");
	a->Loop("qqZZ");
	a->PlotMass();
	a->PlotD();
	//cout<<a->_EventNumber<<endl;
	

}
