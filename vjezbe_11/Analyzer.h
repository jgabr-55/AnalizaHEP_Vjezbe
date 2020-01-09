#include <iostream>
#include <string>
#include <TMath.h>

using namespace std;

class Analyzer{

public:
	
	double Binomna(int r, double p, int N);
	long int Fakt(int broj);
	double CP_upper(int r,int N, double conf_int);
	double CP_lower(int r,int N, double conf_int);
	void ClopperPearson(int N, double CL);
	
};
