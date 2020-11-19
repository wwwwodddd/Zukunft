#include<stdio.h>
typedef long long ll;
int p=100000007;
ll n,m;
ll pw(ll x,ll y)
{
	ll _=1;
	for(x%=p;y;y>>=1,x=x*x%p)
		if(y&1)
			_=_*x%p;
	return _;
}
ll C(ll x,ll y)
{
	x%=p;
	ll u=1,v=1;
	for(int i=0;i<y;i++)
		u=u*(x-i)%p,v=v*(i+1)%p;
	return u*pw(v,p-2)%p;
}
int main()
{
	for(;~scanf("%I64d%I64d",&n,&m);)
		printf("%I64d\n",C(n*m+1,n)*pw(m*n+1,p-2)%p);
	return 0;
}
