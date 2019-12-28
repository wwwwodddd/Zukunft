#include<stdio.h>
#include<math.h>
double m,s,r,d;
int n;
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%lf %lf %lf",&d,&r,&s);
		printf("%.0lf\n",3.1415926535/asin((s+r)/(d-r))-0.5);
	}
}