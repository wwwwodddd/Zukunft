#include<stdio.h>
int n,k,v[1000020];
long long z,t=2,c=1,p=1000000007;
int main()
{
	scanf("%d %d",&n,&k);
	v[1]=1;
	for(int i=2;i<=n;i++)
		v[i]=v[p%i]*(p-p/i)%p;
	for(int i=n-k;~i;i--)
	{
		if(i&1)
			z=(z-c*(t-1))%p;
		else
			z=(z+c*(t-1))%p;
		c=c*i%p*v[n-k-i+1]%p;
		t=t*t%p;
	}
	for(int i=0;i<k;i++)
		z=z*(n-i)%p*v[i+1]%p;
	printf("%lld",(z+p)%p);
	return 0;
}
