#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#define X first
#define Y second
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
typedef long long ll;
typedef pair<ll,ll>LL;
ll n,p=998244353;
ll read()
{
	ll n=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar())
		;
	for(;isdigit(c);c=getchar())
		n=(n*10+c-'0')%(2*p+2);
	return n;
}
LL F(ll n)
{
	if(n==0)
		return LL(0,1);
	else if(n&1)
	{
		LL u=F(n-1);
		return LL(u.Y,(u.X+u.Y)%p);
	}
	else
	{
		LL u=F(n/2);
		return LL((2*u.Y+p-u.X)%p*u.X%p,(u.X*u.X+u.Y*u.Y)%p);
	}
}
int main()
{
	int t=read();
	while(t--)
		cout<<F(read()).X<<endl;
}
