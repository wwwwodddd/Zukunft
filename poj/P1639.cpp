#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
map<string,int>g;
int Q(string s)
{
	if(!g.count(s))
	{
		int u=g.size();
		g[s]=u;
	}
	return g[s];
}
int k,n,m,x,y,z,s,mst,rt,ans;
int d[300],p[300],f[300],v[300],mx[300],a[300][300],e[300][300];
string s1,s2;
void dfs(int x,int y)
{
	p[x]=y;
	for(int i=0;i<n;i++)
		if(i!=y&&e[x][i])
			dfs(i,x);
}
void prim(int q)
{
	d[q]=0;
	z=0x3f3f3f3f;
	rt=q;
	while(1)
	{
		y=0x3f3f3f3f;
		for(int i=0;i<n;i++)
			if(!v[i]&&y>d[i])
				y=d[x=i];
		if(y>0xffffff)
			break;
		v[x]=1;
		if(z>a[s][x])
			z=a[s][rt=x];
		if(x!=q)
			e[f[x]][x]=e[x][f[x]]=1;
		ans+=y;
		for(int i=0;i<n;i++)
			if(!v[i]&&d[i]>a[x][i])
				d[i]=a[x][i],f[i]=x;
	}
	ans+=z;
	dfs(rt,s);
	return;
}
int MX(int x)
{
	if(p[x]==s)
		return -1;
	if(mx[x]!=-1)
		return mx[x];
	int u=MX(p[x]);
	if(u!=-1&&a[u][p[u]]>a[x][p[x]])
		mx[x]=u;
	else
		mx[x]=x;
	return mx[x];
}
void work()
{
	for(int i=0;i<n;i++)
		if(!v[i])
			prim(i),mst++;
	for(;mst<k;mst++)
	{
		memset(mx,-1,sizeof mx);
		for(int i=0;i<n;i++)
			if(mx[i]==-1&&i!=s&&p[i]!=s)
				MX(i);
		y=0x3f3f3f3f;
		for(int i=0;i<n;i++)
			if(mx[i]!=-1&&y>a[s][i]-a[mx[i]][p[mx[i]]])
				y=a[s][x=i]-a[mx[i]][p[mx[i]]];
		if(y>=0)
			break;
		ans+=y;
		e[mx[x]][p[mx[x]]]=e[p[mx[x]]][mx[x]]=0;
		e[s][x]=e[x][s]=1;
		dfs(x,s);
		p[x]=s;
	}
}
int main()
{
	scanf("%d",&m);
	memset(a,0x3f,sizeof a);
	memset(d,0x3f,sizeof d);
	for(int i=0;i<m;i++)
	{
		cin>>s1>>s2>>z;
		x=Q(s1),y=Q(s2);
		a[x][y]=a[y][x]=z;
	}
	scanf("%d",&k);
	n=g.size();
	s=Q("Park");
	v[s]=1;
	work();
	printf("Total miles driven: %d\n",ans);
}
