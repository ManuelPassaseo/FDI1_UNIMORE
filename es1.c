#include <math.h>

double area_trapezio(double a, double b, double c, double d)
{
	double ris1 = (a + b) / 2;
	double ris2 = c * c;
	double ris3 = (b-a) + (  ((c * c) - (d* d) )  / (b-a));
	double ris3doppio=(ris3*ris3 ) /4;

	return ris1* sqrt(ris2 - ris3doppio);
}

int main(void)
{
	double k=area_trapezio(2.2, 3.1, 2.4, 2.9);

	return 0;
}