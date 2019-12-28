#include<stdio.h>
#include<math.h>
const double pi=3.1415926535;
double r,x;
int t,n,k;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf %d",&r,&n);
		printf("Scenario #%d:\n%.3lf\n\n",++k,r*sin(pi/n)/(1+sin(pi/n)));
	}
	return 0;
}