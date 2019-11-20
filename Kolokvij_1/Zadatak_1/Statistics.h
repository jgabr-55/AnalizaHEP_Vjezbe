#include<iostream>
#include<math.h>
#include<time.h>
#include<stdlib.h>

using namespace std;

class Statistics
{
	public:
		void CalculatePi(int N_ukupno);		
		int radijus;
		void NormalDistribution(double x, double mi, double sigma);

		Statistics();
};


