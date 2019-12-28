#include<stdio.h>
#include<math.h>
const double g=9.81;
double m,h,l,k,v;
int main()
{
	while(scanf("%lf%lf%lf%lf",&k,&l,&h,&m)&&k+l+h+m)
		if(l>=h)
		{
			if(h*2*g<=100)
				printf("James Bond survives.\n");
			else
				printf("Killed by the impact.\n");
		}
		else if(l<h)
		{
			if(k/2*(h-l)*(h-l)>m*g*h)
				printf("Stuck in the air.\n");
			else if(2.0*g*h-k*(h-l)*(h-l)/m<=100)
				printf("James Bond survives.\n");
			else
				printf("Killed by the impact.\n");
		}
	return 0;
}
