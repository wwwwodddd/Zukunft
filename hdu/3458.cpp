#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> ii;
pair<ii,int>a[200020];
pair<ii,ii>p[200020];
int l[200020],lc;
int c[100020];
int f[100020];
int n;
void R(int x,int y)
{
	for(x++;x<=n;x+=x&-x)
		c[x]=max(c[x],y);
}
int G(int x)
{
	int _=0;
	for(x++;x;x-=x&-x)
		_=max(_,c[x]);
	return _;
}
int Q(int x)
{
	return lower_bound(l,l+lc,x+1)-l-1;
}
int main()
{
	while(scanf("%d",&n),n)
	{
		lc=0;
		memset(l,0,sizeof l);
		memset(f,0,sizeof f);
		memset(c,0,sizeof c);
		for(int i=0;i<n;i++)
		{
			scanf("%d %d %d %d",&p[i].X.X,&p[i].X.Y,&p[i].Y.X,&p[i].Y.Y);
			a[i]=make_pair(p[i].X,i);
			a[i+n]=make_pair(p[i].Y,i+n);
			l[lc++]=p[i].Y.Y;
		}
		sort(l,l+lc);
		lc=unique(l,l+lc)-l;
		sort(a,a+2*n);
		for(int i=0;i<2*n;i++)
		{
			if(a[i].Y<n)
				f[a[i].Y]=G(Q(a[i].X.Y-1))+1;
			else
				R(Q(a[i].X.Y),f[a[i].Y-n]);
		}
		printf("%d\n",*max_element(f,f+n));
	}
	return 0;
}
