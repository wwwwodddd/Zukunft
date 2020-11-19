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
int n,k;
long long l,r;
long long a[1020];
int v[70];
int w[70];
long long c[70];
long long s[70];
long long F(long long x)
{
	long long _=0;
	long long u=0;
	for(int i=k;i;i--)
	{
		if(!v[i]&&u+c[i]<=x)
		{
			_+=1LL<<w[i]-1;
			u+=c[i];
		}
	}
	if(u<=x)
		_++;
	return _;
}
int main()
{
	cin>>n>>k>>l>>r;
	fr(i,n)
		cin>>a[i];
	for(int i=k;i;i--)
	{
		if(v[i])
			continue;
		c[i]=1LL<<i-1;
		for(int j=i-1;j;j--)
		{
			int k;
			for(k=0;k<n;k++)
				if((a[k]>>i-1&1)!=(a[k]>>j-1&1))
					break;
			if(k==n)
				v[j]=1,c[i]+=1LL<<j-1;
		}
	}
	for(int i=1;i<=k;i++)
		w[i]=w[i-1]+!v[i];
	cout << F(r)-F(l-1) << endl;
}
