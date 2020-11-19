#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define fr(i,n) for(int i=0;i<n;i++)
#define RT(x) (L(F(x))!=x&&R(F(x))!=x)
using namespace std;
int n,m,tot;
int a[60020][2];
int h[30020];
struct N
{
	int w,mx,sm;
#define W(x) t[x].w
#define M(x) t[x].mx
#define S(x) t[x].sm
	int a[2],f;
#define L(x) t[x].a[0]
#define R(x) t[x].a[1]
#define F(x) t[x].f
}t[30020];
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
	return R(F(x))==x;	
}
void sc(int x,int y,int z)
{
	t[x].a[z]=y;
	F(y)=x;
}
void ud(int x)
{
	M(x)=max(max(M(L(x)),M(R(x))),W(x));
	S(x)=S(L(x))+S(R(x))+W(x);
}
void rtt(int x)
{
	int p=F(x);
	int c=d(x);
	sc(p,t[x].a[!c],c);
	F(x)=F(p);
	if(L(F(p))==p)
		L(F(p))=x;
	if(R(F(p))==p)
		R(F(p))=x;
	sc(x,p,!c);
	ud(p);
}
void spy(int x)
{
	while(!RT(x))
		if(RT(F(x)))
			rtt(x);
		else
			d(x)==d(F(x))?rtt(F(x)):rtt(x),rtt(x);
	ud(x);
}
int acs(int x,int o)
{
	for(int z=0;x;x=F(x))
	{
		spy(x);
		if(!F(x))
		{
			if(o==1)
				return max(max(M(R(x)),M(z)),W(x));
			else if(o==2)
				return S(R(x))+S(z)+W(x);
		}
		R(x)=z;
		ud(x);
		z=x;
	}
	return 0;
}
char o[10];
int main()
{

	int x,y;
	for(;scanf("%d",&n)+1;)
	{
		memset(h,0,sizeof h);
		memset(t,0,sizeof t);
		tot=0;
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
			scanf("%s%d%d",o,&x,&y);
			if(*o=='C')
			{
				W(x)=y;
				spy(x);
			}
			else if(o[1]=='M')
			{
				acs(y,0);
				printf("%d\n",acs(x,1));
			}
			else if(o[1]=='S')
			{
				acs(y,0);
				printf("%d\n",acs(x,2));
			}
		}
	}
	return 0;
}
