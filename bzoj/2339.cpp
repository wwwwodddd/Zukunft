#include<stdio.h>
int mo=100000007;
long long a[1000020];
long long f[1000020];
long long pw(long long x,long long y)
{
	long long re=1;
	for(;y;y>>=1)
	{
		if(y&1)
			re=re*x%mo;
		x=x*x%mo;
	}
	return re;
}
long long n,m,u;
int main()
{
	scanf("%lld%lld",&n,&m);
	int t=pw(2,n)-1;
	a[0]=1;
	for(int i=1;i<=m;i++)
		a[i]=a[i-1]*(t-i+1)%mo;
	for(int i=3;i<=m;i++)
	{
		f[i]=(a[i-1]-f[i-1]-f[i-2]*(i-1)%mo*(t-i+2)%mo)%mo;
		if(f[i]<0)
			f[i]+=mo;
	}
	u=1;
	for(int i=1;i<=m;i++)
		u=u*i%mo;
	printf("%d",f[m]*pw(u,mo-2)%mo);
	return 0;
}
