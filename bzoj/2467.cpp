#include<stdio.h>
int t,n,z;
int main()
{
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		z=4*n;
		for(;--n;)
			z=z*5%2007;
		printf("%d\n",z);
	}
	return 0;
}
