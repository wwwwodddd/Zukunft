#include<stdio.h>
int r,k;
double dis,d,s,t;
int main()
{
	while(scanf("%lf %d %lf",&d,&r,&t)&&r)
	{
		dis=d*3.1415927*r/12/5280;
		s=dis/t*3600;
		printf("Trip #%d: %.2lf %.2lf\n",++k,dis,s);
	}
	return 0;
}
