#include "Statistics.h"

int main()
{
	Statistics *obj = new Statistics();
	obj->CalculatePi(1000000);
	obj->NormalDistribution(185.0,178.2,6.4);
	obj->NormalDistribution(205.0,178.2,6.4);
	obj->NormalDistribution(185.0,160.2,7.2);
}
