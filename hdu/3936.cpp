#include<stdio.h>
#include<iostream>
#define X first
#define Y second
using namespace std;
typedef long long ll;
ll p=1000000007,l,r;
int t;
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
ll G(ll x)
{
	pair<ll,ll>u=F(2*x);
	return u.X*u.Y%p;
}
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%I64d %I64d",&l,&r);
		printf("%I64d\n",(G(r)-G(l-1)+3*p)%p);
	}
}
