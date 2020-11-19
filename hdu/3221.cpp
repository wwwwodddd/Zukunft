#include<stdio.h>
#include<iostream>
#define X first
#define Y second
using namespace std;
typedef long long ll;
ll a,b,P,p,n;
pair<ll,ll> F(ll x)
{
	if(x==0)
		return make_pair(0,1);
	else if(x%2==1)
	{
		pair<ll,ll>a=F(x-1);
		return make_pair(a.Y,(a.X+a.Y)%p);
	}
	else
	{
		pair<ll,ll>a=F(x/2);
		return make_pair((a.X*(2*a.Y-a.X))%p,(a.X*a.X+a.Y*a.Y)%p);
	}
}
ll pw(ll x,ll y)
{
	int _=1; 
	for(y+=3*p;y;y>>=1,x=x*x%P)
		y&1?_=_*x%P:0;
	return _;
}
ll phi(ll x)
{
	int _=x;
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
		{
			_=_/i*(i-1);
			while(x%i==0)
				x/=i;
		}
	if(x>1)
		_=_/x*(x-1);
	return _;
}
int t,k;
long long f[10020];
int main()
{
	for(scanf("%d",&t);t--;)
	{
		cin>>a>>b>>P>>n;
		f[1]=a%P,f[2]=b%P;
		for(int i=3;i<=10000;i++)
			f[i]=f[i-1]*f[i-2]%P;
		p=phi(P);
		if(n<=10000)
			printf("Case #%d: %I64d\n",++k,f[n]);
		else
			printf("Case #%d: %I64d\n",++k,pw(a,F(n-2).X)*pw(b,F(n-1).X)%P);
	}
}
