#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define fr(i,n) for(int i=0;i<n;i++)
#define RT(x) (t[t[x].f].a[0]!=x&&t[t[x].f].a[1]!=x)
using namespace std;
const int N=100005;
int n,m,tot;
int a[200020][2];
int h[100020];
struct N
{
	int w,mx,sm;
	int a[2],f;
}t[100020];
void dfs(int x,int y)
{
	t[x].f=y;
	for(int i=h[x];i;i=a[i][0])
		if(a[i][1]!=y)
			dfs(a[i][1],x);
}
void add(int x,int y)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	h[x]=tot;
}
int d(int x)
{
	return t[t[x].f].a[1]==x;	
}
void sc(int x,int y,int z)
{
	t[x].a[z]=y;
	t[y].f=x;
}
void ud(int x)
{
	t[x].mx=max(max(t[t[x].a[0]].mx,t[t[x].a[1]].mx),t[x].w);
	t[x].sm=t[t[x].a[0]].sm+t[t[x].a[1]].sm+t[x].w;
}
void rtt(int x)
{
	int p=t[x].f;
	int c=d(x);
	sc(p,t[x].a[!c],c);
	t[x].f=t[p].f;
	if(t[t[p].f].a[0]==p)
		t[t[p].f].a[0]=x;
	if(t[t[p].f].a[1]==p)
		t[t[p].f].a[1]=x;
	sc(x,p,!c);
	ud(p);
}
void spy(int x)
{
	while(!RT(x))
		if(RT(t[x].f))
			rtt(x);
		else
			d(x)==d(t[x].f)?rtt(t[x].f):rtt(x),rtt(x);
	ud(x);
}
void acs(int x)
{
	for(int z=0;x;x=t[x].f)
	{
		spy(x);
		t[x].a[1]=z;
		ud(x);
		z=x;
	}
}
int QM(int x)
{
	for(int z=0;x;x=t[x].f)
	{
		spy(x);
		if(!t[x].f)
			return max(max(t[t[x].a[1]].mx,t[z].mx),t[x].w);
		t[x].a[1]=z;
		ud(x);
		z=x;
	}
}
int QS(int x)
{
	for(int z=0;x;x=t[x].f)
	{
		spy(x);
		if(!t[x].f)
			return t[t[x].a[1]].sm+t[z].sm+t[x].w;
		t[x].a[1]=z;
		ud(x);
		z=x;
	}
}
char o[10];
int main()
{
	freopen("c.in","r",stdin);
	int x,y;
	scanf("%d",&n);
	fr(i,n-1)
		scanf("%d%d",&x,&y),add(x,y),add(y,x);
	t[0].mx=-0xffffff;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t[i].w);
		t[i].mx=t[i].w;
	}
	dfs(1,0);
	scanf("%d",&m);
	fr(i,m)
	{
		int x,y;
		scanf("%s%d%d",o,&x,&y);
		if(*o=='C')
		{
			t[x].w=y;
			spy(x);
		}
		else if(o[1]=='M')
		{
			acs(y);
			printf("%d\n",QM(x));
		}
		else if(o[1]=='S')
		{
			acs(y);
			printf("%d\n",QS(x));
		}
	}
	while(1);
	return 0;
}
