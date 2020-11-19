#include<stdio.h>
#include<math.h>
long long z,i,t;
double n,d;
int main()
{
	while(scanf("%lf %lf",&n,&d)+1)
	{
		t=0;
		z=(int)ceil(n/d);
		for(i=1;z>i;i++)
		{
			t+=1+i;
			z-=i;
		}
		t+=z;
		printf("%I64d\n",t);
	}
	return 0;
}