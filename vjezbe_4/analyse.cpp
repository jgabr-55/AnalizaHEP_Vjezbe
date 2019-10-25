#include "Analyzer.h"

using namespace std;

int main(){

	Analyzer *a = new Analyzer();
	a->ReadFile();
	cout<<a->_EventNumber<<endl;
	

}
