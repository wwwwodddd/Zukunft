#include<stdio.h>
int n,t,k,z;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		z=1;
		scanf("%d",&n);
		for(int i=2;i*i<=n;i++)
		{
			int o=1;
			while(n%i==0)
				n/=i,o+=2;
			z*=o;
		}
		if(n>1)
			z*=3;
		printf("Scenario #%d:\n%d\n\n",++k,z+1>>1);
	}
	return 0;
}
