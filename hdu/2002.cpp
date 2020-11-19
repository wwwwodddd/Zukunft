#include<stdio.h>
#define pi 3.1415927
double r;
int main()
{
	while(scanf("%lf",&r)+1)
		printf("%.3lf\n",r*r*r*pi*4/3);
}