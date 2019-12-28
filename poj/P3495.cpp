#include<stdio.h>
typedef long long ll;
ll x,y,z,n,ans;
ll mk(ll a,ll d,ll m,ll n)
{
	if(!n)
		return 0;
	ll _=a/m*n+d/m*(n-1)*n/2;
	a%=m,d%=m;
	return _+mk((a+d*n)%m,m,d,(a+d*n)/m);
}
int main()
{
	for(;~scanf("%I64d%I64d%I64d",&x,&y,&z);)
	{
		ans=0;
		n=(y-x)/z+1;
		for(int i=0;i<32;i++)
			ans+=(mk(x,z,1LL<<i,n)&1)<<i;
		printf("%I64d\n",ans);
	}
}
