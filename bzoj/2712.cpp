#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
typedef long long ll;
int work(ll a,ll b,ll c,ll d,ll &x,ll &y)
{
	if(!d||a/b<(c-1)/d)
		return x=a/b+1,y=1,0;
	ll t=min(c/d,a/b);
	work(d,c-t*d,b,a-t*b,y,x);
	x+=a/b*y;
}
int l;
ll n;
int main()
{
	while(~scanf("%d 0.%lld",&l,&n))
		if(n)
		{
			ll m=2;
			while(l--)
				m*=10;
			ll x,y;
			work(2*n-1,m,2*n+1,m,x,y);
			ll g=__gcd(2*n-1,m);
			y=min(y,m/g);
			printf("%lld\n",y);
		}
		else
			puts("1");
}
