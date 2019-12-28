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
int f[1000020];
int x[25020],y[25020],z[25020];
int n,q;
int F(int x)
{
	return f[x]!=x?f[x]=F(f[x]):x;
}
struct N
{
	int x,y,z;
}a[25020];
bool operator<(const N&a,const N&b)
{
	return a.z>b.z;
}
int ok(int m)
{
	for(int i=1;i<=m;i++)
	{
		a[i].x=x[i];
		a[i].y=y[i];
		a[i].z=z[i];
	}
	sort(a+1,a+1+m);
	for(int i=0;i<=n;i++)
		f[i]=i;
	for(int j,i=1;i<=m;i=j)
	{
		int mn=0,mx=0xffffff;
		for(j=i;j<=m&&a[i].z==a[j].z;j++)
			mn=max(mn,a[j].x),mx=min(mx,a[j].y);
		if(F(mx)<mn)
			return 0;
		for(j=i;j<=m&&a[i].z==a[j].z;j++)
			for(int k=F(a[j].y);k>=a[j].x;k=F(k))
				f[k]=k-1;
	}
	return 1;
}
int main()
{
	scanf("%d %d",&n,&q);
	for(int i=1;i<=q;i++)
		scanf("%d %d %d",x+i,y+i,z+i);
	if(ok(q))
	{
		puts("0");
		return 0;
	}
	int l=1,r=q;
	while(l<r)
	{
		if(ok((l+r)/2))
			l=(l+r)/2+1;
		else
			r=(l+r)/2;
	}
	printf("%d\n",l);
	return 0;
}
