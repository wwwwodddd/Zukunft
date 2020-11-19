#include<stdio.h>
long long x,y,z;
int n;
int main()
{
	while(scanf("%d",&n),n+1)
	{
		x=1;
		y=0;
		for(int i=0;i<n;i++)
		{
			z=3*x+2*y;
			y=x+y;
			x=z;
		}
		printf("%I64d, %I64d\n",x,y);
	}
}
