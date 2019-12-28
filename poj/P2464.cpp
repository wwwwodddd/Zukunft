#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define X first
#define Y second
using namespace std;
int c[200020];
int l[200020],lc;
int s[200020];
int o[200020];
int n,x,y,z;
typedef pair<int,int>ii;
ii a[200020];
void R(int x,int y)
{
	for(x++;x<=n;x+=x&-x)
		c[x]+=y;
}
int G(int x)
{
	int _=0;
	for(x++;x;x-=x&-x)
		_+=c[x];
	return _;
}
int main()
{
	for(;scanf("%d",&n),n;)
	{
		lc=0,z=-1;
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&a[i].X,&a[i].Y);
			l[lc++]=a[i].Y;
		}
		sort(l,l+lc),lc=unique(l,l+lc)-l;
		for(int i=0;i<n;i++)
			a[i].Y=lower_bound(l,l+lc,a[i].Y)-l;
		sort(a,a+n);
		memset(c,0,sizeof c);
		memset(s,0,sizeof s);
		memset(o,0,sizeof o);
		for(int j,i=0;i<n;i=j)
		{
			for(j=i;j<n&&a[j].X==a[i].X;j++)
			{
				s[j]+=G(a[j].Y-1);
				o[j]+=i-G(a[j].Y);
			}
			for(j=i;j<n&&a[j].X==a[i].X;j++)
				R(a[j].Y,1);
		}
		reverse(a,a+n);
		memset(c,0,sizeof c);
		for(int j,i=0;i<n;i=j)
		{
			for(j=i;j<n&&a[j].X==a[i].X;j++)
			{
				o[n-j-1]+=G(a[j].Y-1);
				s[n-j-1]+=i-G(a[j].Y);
			}
			for(j=i;j<n&&a[j].X==a[i].X;j++)
				R(a[j].Y,1);
		}
		reverse(a,a+n);
		for(int j,i=0;i<n;i=j)
		{
			x=0xffffff,y=-1;
			for(j=i;j<n&&a[j].X==a[i].X;j++)
				if(y<o[j])
					y=o[j],x=s[j];
				else if(y==o[j])
					x=min(x,s[j]);
			if(z<x)
				z=x,lc=0;
			if(x==z)
				l[lc++]=y;
		}
		sort(l,l+lc),lc=unique(l,l+lc)-l;
		printf("Stan: %d; Ollie:",z);
		for(int i=0;i<lc;i++)
			printf(" %d",l[i]);
		puts(";");
	}
	return 0;
}
