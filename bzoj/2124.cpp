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
long long c1[100020];
long long c2[100020];
long long c[100020];
int a[100020];
int t,n;
void R(int x,long long y,long long *c)
{
	for(;x<=n;x+=x&-x)
		c[x]+=y;
}
long long G(int x,long long *c)
{
	long long _=0;
	for(;x;x-=x&-x)
		_+=c[x];
	return _;
}
int main()
{
	c[0]=1;
	for(int i=1;i<10010;i++)
		c[i]=c[i-1]*9901;
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		memset(c1,0,sizeof c1);
		memset(c2,0,sizeof c2);
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		for(int i=0;i<n;i++)
		{
			R(a[i],c[a[i]],c1);
			R(n-a[i]+1,c[n-a[i]+1],c2);
			if(n-a[i]>a[i]-1)
			{
				long long h1=G(a[i]-1,c1)*c[n-2*a[i]+1];
				long long h2=G(n-a[i],c2)-G(n-2*a[i]+1,c2);
				if(h1!=h2)
				{
					puts("Y");
					goto end;
				}
			}
			else
			{
				long long h2=G(n-a[i],c2)*c[2*a[i]-n-1];
				long long h1=G(a[i]-1,c1)-G(2*a[i]-n-1,c1);
				if(h1!=h2)
				{
					puts("Y");
					goto end;
				}
			}
		}
		puts("N");
		end:;
	}
}
