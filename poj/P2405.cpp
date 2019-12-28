#include <math.h>
#include <stdio.h>
const double pi=3.1415926535;
double d,v;
int main()
{
	while(scanf("%lf%lf",&d,&v)&&d+v)
		printf("%.3lf\n",pow(d*d*d-6*v/pi,1.0/3));
}
