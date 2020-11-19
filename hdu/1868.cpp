#include<stdio.h>
long long n;
int z;
int main()
{
	while(~scanf("%I64d",&n))
	{
		z=0;
		for(long long i=2;i*(i+1)/2<=n;i++)
			if((n-i*(i+1)/2)%i==0)
				z++;
		printf("%d\n",z);
	}
}

