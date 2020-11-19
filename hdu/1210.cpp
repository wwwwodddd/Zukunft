#include<stdio.h>
int n,x,z;
int F(int x)
{
	return x<=n?2*x:2*x-2*n-1;
}
int main()
{
	while(~scanf("%d",&n))
	{
		z=0;
		for(x=1;F(x)!=1;x=F(x))
			z++;
		printf("%d\n",z+1);
	}
	return 0;
}
