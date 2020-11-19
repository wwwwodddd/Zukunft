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
int t[1000020][2],tt=1;
int c[1000020];
int d[1000020];
int a[1000020];
int n,m,l;
void ins()
{
	int p=1;
	fr(i,l)
	{
		if(!t[p][a[i]])
			t[p][a[i]]=++tt;
		p=t[p][a[i]];
		c[p]++;
	}
	d[p]++;
}
int qy()
{
	int _=0,p=1;
	fr(i,l)
	{
		_+=d[p];
		if(!t[p][a[i]])
			return _;
		p=t[p][a[i]];
	}
	return _+c[p];
}
int main()
{
	scanf("%d %d",&n,&m);
	fr(i,n)
	{
		scanf("%d",&l);
		fr(j,l)
			scanf("%d",a+j);
		ins();
	}
	fr(i,m)
	{
		scanf("%d",&l);
		fr(j,l)
			scanf("%d",a+j);
		printf("%d\n",qy());
	}
	return 0;
}
