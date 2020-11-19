#include<stdio.h>
int n,k;
long long z,l,r;
int main()
{
	for(;~scanf("%d %d",&n,&k);z=0)
	{
		for(l=1;l<=n;l=r+1)
		{
			r=k/l?k/(k/l):n;
			if(r>n)
				r=n;
			z+=(r-l+1)*k-k/l*(l+r)*(r-l+1)/2;
		}
		printf("%I64d\n",z);
	}
	return 0;
}
