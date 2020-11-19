#include<stdio.h>
double l;
int main()
{
	while(scanf("%lf",&l),l)
		printf("%.2lf\n",l*l/6.283185307);
	return 0;
}