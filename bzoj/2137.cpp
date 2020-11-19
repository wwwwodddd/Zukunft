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
int p=1000000007;
int n,k;
long long a[30][30];
long long f[100020];
long long d[100020];
long long pw(long long x,long long y)
{
	long long _=1;
	for(;y;y>>=1)
	{
		if(y&1)
			_=_*x%p;
		x=x*x%p;
	}
	return _;
}
namespace A
{
	long long C(int x,int y)
	{
		long long _=1;
		for(int i=0;i<y;i++)
			_=_*(x-i)%p*pw(i+1,p-2)%p;
		return _%p;
	}
	long long cal(long long n)
	{
		n%=p;
		long long _=0;
		fo(i,k+1)
			_=(_+C(n,i)*a[i][i])%p;
		return _;
	}
	void init()
	{
		for(int i=1;i<=k+1;i++)
			a[1][i]=pw(i,k);
		for(int i=2;i<=k+1;i++)
			for(int j=i;j<=k+1;j++)
				a[i][j]=(a[i-1][j]-a[i-1][j-1])%p;
	}
	void work()
	{
		init();
		long long z=1;
		fo(i,n)
			z=z*cal(d[i]+1)%p;
		cout << (z+p)%p << endl;
	}
}
namespace B
{
	void init()
	{
		fo(i,100010)
			f[i]=(f[i-1]+pw(i,k))%p;
	}
	void work()
	{
		init();
		long long z=1;
		fo(i,n)
			z=z*f[d[i]+1]%p;
		cout << (z+p)%p << endl;
	}
}
int main()
{
	scanf("%d %d",&n,&k);
	fo(i,n)
		scanf("%lld",d+i);
	if(k<20)
		A::work();
	else
		B::work();
	return 0;
}
