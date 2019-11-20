#include "Statistics.h"

Statistics::Statistics()
{
	cout<<"Objekt je uspješno kreiran"<<endl;	
}

void Statistics::CalculatePi(int N_ukupno)
{
	srand (time(NULL));
	double x_random, y_random;
	int N_krug=0;
	//stranica_kvadrata = 100;
	radijus=50;
	for(int i=0;i<N_ukupno;i++)
	{
		x_random=rand() % 100 - 50;
		y_random=rand() % 100 - 50;
		
		if(sqrt(pow(x_random,2) + pow(y_random,2))<=radijus)
			N_krug = N_krug + 1;  
	}
	
	cout<<((double)N_krug/N_ukupno)*4.0<<endl;
	
}

void Statistics::NormalDistribution(double x, double mi, double sigma)
{
	double eksponencijalni_clan = -1.*(pow((x-mi),2)/(2.*sigma*sigma));
	double vrijednost = (1./(sigma*sqrt(2*3.14)))*exp(eksponencijalni_clan);
	cout<<vrijednost<<endl;
}
