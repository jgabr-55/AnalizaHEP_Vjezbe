#include "Analyzer.h"
#include<stdlib.h>
#include<time.h>

using namespace std;

int main(){

	Analyzer *a = new Analyzer();
	//cout<<a->Binomna(3,0.001,10)<<endl;
	/*cout<<a->Binomna(0,0.25,10)<<endl;
	cout<<a->Binomna(10,0.25,10)<<endl;
	cout<<a->Binomna(2,0.0,10)<<endl;
	cout<<a->Binomna(2,1.0,10)<<endl;*/
	/*cout<<a->CP_upper(2,10,0.6827)<<endl;
	cout<<a->CP_lower(2,10,0.6827)<<endl;*/
	//cout<<a->_EventNumber<<endl;
	a->ClopperPearson(11,0.6827);

	/*srand(time(NULL));

	int r=0, br2=0;
	
	for(int i=1;i<=1000;i++){
	for(int j=1;j<=10;j++)
	{
		int bacanje = rand() % 6 + 1;
		if(bacanje==6)
			r++;
	}

	if(r==0)
		br2++;
	else if((1./6)>a->CP_lower(r,10,0.9) && (1./6)<a->CP_upper(r,10,0.9))
		br2++;

	r=0;
	
}

cout<<br2/10.<<endl;*/

}
