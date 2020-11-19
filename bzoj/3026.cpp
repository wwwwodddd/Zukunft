#include<stdio.h>
#include<iostream>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<ll,ll>LL;
ll n,k,f[10020],z;
int w[5]={2,3,11,2089,7253},c=5,p=1000000122;
ll pw(ll x,ll y,ll z)
{
	ll _=1;
	for(;y;y>>=1,x=x*x%z)
		if(y&1)
			_=_*x%z;
	return _;
}
LL F(int n,int p)
{
	if(n==0)
		return LL(1,0);
	LL u=F(n/p,p);
	u.Y+=n/p;
	u.X=u.X*pw(f[p-1],n/p,p)*f[n%p]%p;
	return u;
}
int main()
{
	for(;~scanf("%lld%lld",&n,&k);z=0)
	{
		for(int i=0;i<c;i++)
		{
			f[0]=1;
			for(int j=1;j<w[i];j++)
				f[j]=f[j-1]*j%w[i];
			LL a=F(2*n,w[i]),b=F(n+1,w[i]),c=F(n,w[i]);
			a.Y-=b.Y+c.Y;
			a.X=a.X*pw(b.X,w[i]-2,w[i])%w[i]*pw(c.X,w[i]-2,w[i])%w[i];
			if(a.Y)
				a.X=0;
			z=(z+p/w[i]*pw(p/w[i],w[i]-2,w[i])%p*a.X)%p;
		}
		printf("%lld\n",pw(k,z,p+1));
	}
	return 0;
}
