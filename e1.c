#include <math.h>

double newton(double m1, double m2, double d)
{
	if (m1 < 0 || m2 < 0 || d < 0)return -1;
	double g = 6.67259 * pow(10, -11);

	return (g * (m1 * m2)) /( d * d);
}



int main(void)
{
	double k=newton(5.97e+24, 6.70e+22, 3.84e+08);

	return 0;
}