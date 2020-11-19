#include<stdio.h>
int main()
{
	long long l,a,b,p;
	int n;
	while(~scanf("%d%I64d%I64d%I64d%I64d",&n,&l,&a,&b,&p))
	{
		a%=p;
		long long mx=0,mn=1LL<<60,o=l/2,t=b%p;
		int i,z=0;
		for(i=1;i<=n;i++)
		{
			t+=a;
			if(t>=p)
				t-=p;
			if(t>o)
			{
				if(mn>t)
					mn=t;
			}
			else
			{
				if(mx<t)
					mx=t;
				z++;
			}
		}
		if(mn+mx<=l)
			z++;
		printf("%d\n",z);
	}
	return 0;
}
