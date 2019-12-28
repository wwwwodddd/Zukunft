#include<stdio.h>
#include<math.h>
int n;
double x[1020],y[1020];
int main()
{
	for(;scanf("%d",&n);)
	{
		double z=0;
		for(int i=0;i<n;i++)
			scanf("%lf %lf",x+i,y+i);
		x[n]=*x,y[n]=*y;
		for(int i=0;i<n;i++)
			z+=x[i]*y[i+1]-x[i+1]*y[i];
		printf("%.f\n",fabs(z/2));
	}
	return 0;
}
