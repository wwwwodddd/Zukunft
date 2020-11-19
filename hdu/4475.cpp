#include<stdio.h>
int t,p=1000003;
long long f[1000020],n;
long long pw(long long x,long long y)
{
	long long _=1;
	for(;y;y>>=1)
		y&1?_=_*x%p:0,x=x*x%p;
	return _;
}
int main()
{
	f[0]=1;
	for(int i=1;i<=p;i++)
		f[i]=f[i-1]*2*i%p;
	for(scanf("%d",&t);t--;)
	{
		scanf("%I64d",&n);
		printf("%I64d\n",f[n%p]*pw(f[p],n/p));
	}
	return 0;
}
