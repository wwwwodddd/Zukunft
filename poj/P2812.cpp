#include<stdio.h>
double x[2020],y[2020],s,c;
int i,n;
int main()
{
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
			scanf("%lf%lf",&x[i],&y[i]);
		x[n]=x[0];
		y[n]=y[0];
		s=0;
		for(i=0;i<n;i++)
			s+=x[i]*y[i+1]-x[i+1]*y[i];
		if(s<0)
			s=-s;
		scanf("%lf",&c);
		printf("BAR LENGTH: %.2lf\n",c/s*2);
	}
	return 0;
}