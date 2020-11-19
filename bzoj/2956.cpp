#include<stdio.h>
#include<iostream>
using namespace std;
typedef long long ll;
int n,m,p=19940417;
ll Q(ll x)
{
	ll z=0;
	for(ll i=1;i<=x;i++)
	{
		ll t=(x/(x/i));
		z+=(t-i+1)*x%p-(i+t)*(t-i+1)/2%p*(x/i)%p;
		z%=p;
		i=t;
	}
	return z%p;
}
ll K(ll x,ll y)
{
	ll z=0;
	for(ll i=1;i<=min(x,y);i++)
	{
		ll t=min((x/(x/i)),y/(y/i)),l=t-i;
		z+=(x%t)*(y%t)%p*(l+1)%p+l*(l+1)%p*(2*l+1)%p*3323403%p*(x/i)%p*(y/i)%p+l*(l+1)/2%p*(y%t)%p*(x/i)%p+l*(l+1)/2%p*(x%t)%p*(y/i)%p;
		z%=p;
		i=t;
	}
	return z%p;
}
int main()
{
	scanf("%d%d",&n,&m);
	cout<<(Q(n)*Q(m)%p+2*p-K(n,m))%p<<endl;
	return 0;
}
