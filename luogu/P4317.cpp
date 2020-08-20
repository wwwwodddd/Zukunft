#include<stdio.h>
typedef long long ll;
ll p=10000007;
ll c[60][60],n;
ll pw(ll x,ll y)
{
	ll z=1;
	for(;y;y>>=1,x=x*x%p)
		if(y&1)
			z=z*x%p;
	return z;
}
ll F(int x,ll n)
{
	ll ans=0;
	for(int i=55;i--;)
		if(n>>i&1&&x>=0)
			ans+=c[i][x--];
	return ans;
}
int main()
{
	for(int i=0;i<60;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)
			c[i][j]=c[i-1][j]+c[i-1][j-1];
	}
	scanf("%lld",&n),n++;
	ll ans=1;
	for(int i=2;i<55;i++)
		ans=ans*pw(i,F(i,n))%p;
	printf("%lld",ans);
}