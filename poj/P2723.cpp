#include<stdio.h>
#include<iostream>
using namespace std;
int dfn[5020],low[5020];
int a[20020][3];
int h[5020],tot;
int f[2020][2];
int g[2020][2];
int scc,cnt,ss;
int s[5020];
int v[5020];
int r[5020];
int n,m;
void add(int x,int y)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	h[x]=tot;
	return;
}
void tarjan(int x)
{
	int y,i,j;
	cnt++;
	dfn[x]=low[x]=cnt;
	v[x]=1;
	s[ss++]=x;
	for(i=h[x];i;i=a[i][0])
	{
		if(dfn[a[i][1]]==0)
		{
			tarjan(a[i][1]);
			if(low[x]>low[a[i][1]])
				low[x]=low[a[i][1]];
		}
		else if(v[a[i][1]]==1&&low[x]>dfn[a[i][1]])
			low[x]=dfn[a[i][1]];
	}
	if(dfn[x]==low[x])
	{
		scc++;
		do
		{
			y=s[--ss];
			r[y]=scc;
			v[y]=0;
		}
		while(x!=y);
	}
}
int check(int mid)
{
	int i;
	tot=scc=cnt=ss=0;
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(s,0,sizeof(s));
	memset(v,0,sizeof(v));
	memset(r,0,sizeof(r));
	memset(a,0,sizeof(a));
	memset(h,0,sizeof(h));
	for(i=0;i<n;i++)
	{
		add(f[i][0],f[i][1]+2*n);
		add(f[i][1],f[i][0]+2*n);
	}
	for(i=0;i<mid;i++)
	{
		add(g[i][0]+2*n,g[i][1]);
		add(g[i][1]+2*n,g[i][0]);
	}
	for(i=0;i<4*n;i++)
		if(dfn[i]==0)
			tarjan(i);
	for(i=0;i<2*n;i++)
		if(r[i]==r[i+2*n])
			return 0;
	return 1;
}
int bs()
{
	int l=0,r=m;
	while(l<r)
	{
		if(check((l+r+1)/2))
			l=(l+r+1)/2;
		else
			r=(l+r+1)/2-1;
	}
	return r;
}
int main()
{
	int i;
	while(scanf("%d %d",&n,&m),n+m)
	{
		for(i=0;i<n;i++)
			scanf("%d %d",&f[i][0],&f[i][1]);
		for(i=0;i<m;i++)
			scanf("%d %d",&g[i][0],&g[i][1]);
		printf("%d\n",bs());
	}
	return 0;
}