#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int a[200020],b[200020],c[200020];
int e[2000020][2],tot;
int q[200020],o,p;
int f[200020][18];
int d[200020];
int h[200020];
int s[200020],ss;
int v[200020];
int n,m,x,y,t;
void add(int x,int y,int *h)
{
	tot++;
	e[tot][0]=h[x];
	e[tot][1]=y;
	h[x]=tot;	
}
int lca(int x,int y)
{
	if(h[x]<h[y])
		swap(x,y);
	int k=h[x]-h[y];
	fr(i,18)
		if(k>>i&1)
			x=f[x][i];
	if(x==y)
		return x;
	for(int i=17;~i;i--)
		if(f[x][i]!=f[y][i])
			x=f[x][i],y=f[y][i];
	return f[x][0];
}
void dfs(int x)
{
	s[x]=++ss;
	for(int i=c[x];i;i=e[i][0])
		dfs(e[i][1]);
}
int cmp(const int &x,const int &y)
{
	return s[x]<s[y];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m);
		for(;m--;)
		{
			scanf("%d",&x);
			add(i,x,a);
			add(x,i,b);
			d[i]++;
		}
		add(i,0,a);
		add(0,i,b);
		d[i]++;
	}
	q[p++]=0;
	while(o<p)
	{
		x=q[o++];
		for(int i=b[x];i;i=e[i][0])
			if(!--d[e[i][1]])
				q[p++]=e[i][1];
		if(!x)
			continue;
		y=e[e[a[x]][0]][1];
		for(int i=a[x];i;i=e[i][0])
			if(e[i][1])
				y=lca(y,e[i][1]);
		add(y,x,c);
		h[x]=h[y]+1;
		f[x][0]=y;
		fo(i,17)
			f[x][i]=f[f[x][i-1]][i-1];
	}
	dfs(0);
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&m);
		for(int i=0;i<m;i++)
			scanf("%d",v+i);
		sort(v,v+m,cmp);
		int ans=h[v[0]];
		for(int i=1;i<m;i++)
			ans+=h[v[i]]-h[lca(v[i-1],v[i])];
		printf("%d\n",ans);
	}
}
