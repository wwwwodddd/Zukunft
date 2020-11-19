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
int h[10020];
int g[10020];
int l[10020],bcc;
int len[10020];
int s[10020];
int e[10020];
int d[10020];
int p[10020];
int v[10020];
int low[10020];
int a[200020][3],tot;
int f[10020][16];
void add(int x,int y,int z,int *h=h)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	a[tot][2]=z;
	h[x]=tot;
}
void dfs(int x)
{
	v[x]=1;
	low[x]=e[x];
	for(int i=h[x];i;i=a[i][0])
		if(!v[a[i][1]])
		{
			p[a[i][1]]=i;
			e[a[i][1]]=e[x]+1;
			dfs(a[i][1]);
			low[x]=min(low[x],low[a[i][1]]);
		}
		else if(i^p[x]^1)
			low[x]=min(low[x],e[a[i][1]]);
	for(int i=h[x];i;i=a[i][0])
		if(p[a[i][1]]==i&&low[a[i][1]]>e[x])
		{
			add(x,a[i][1],a[i][2],g);
			f[a[i][1]][0]=x;
		}
		else if(p[a[i][1]]!=i&&e[a[i][1]]>e[x])
		{
			int sm=a[i][2],w=sm;
			for(int j=a[i][1];j!=x;j=a[p[j]^1][1])
				sm+=a[p[j]][2];
			len[++bcc]=sm;
			for(int j=a[i][1];j!=x;j=a[p[j]^1][1])
			{
				add(x,j,min(w,sm-w),g);
				f[j][0]=x;
				l[j]=bcc;
				s[j]=w;
				w+=a[p[j]][2];
			}
		}
}
void mk(int x)
{
	for(int i=1;i<16;i++)
		f[x][i]=f[f[x][i-1]][i-1];
	for(int i=g[x];i;i=a[i][0])
	{
		e[a[i][1]]=e[x]+1;
		d[a[i][1]]=d[x]+a[i][2];
		mk(a[i][1]);
	}
}
int up(int x,int y)
{
	for(int i=0;i<16;i++)
		if(y>>i&1)
			x=f[x][i];
	return x;	
}
int lca(int x,int y)
{
	if(e[x]<e[y])
		swap(x,y);
	x=up(x,e[x]-e[y]);
	if(x==y)
		return x;
	for(int i=15;~i;i--)
		if(f[x][i]!=f[y][i])
			x=f[x][i],y=f[y][i];
	return f[x][0];
}
int main()
{
	tot=1;
	int n,m,q,x,y,z;
	scanf("%d %d %d",&n,&m,&q);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	dfs(1);
	memset(v,0,sizeof v);
	mk(1);
	while(q--)
	{
		int fx,fy;
		scanf("%d %d",&x,&y);
		z=lca(x,y);
		if(z==x||z==y)
			printf("%d\n",d[x]+d[y]-2*d[z]);
		else
		{
			fx=up(x,e[x]-e[z]-1);
			fy=up(y,e[y]-e[z]-1);
			if(!l[fx]||l[fx]!=l[fy])
				printf("%d\n",d[x]+d[y]-2*d[z]);
			else
			{
				int t=min(len[l[fx]]-abs(s[fx]-s[fy]),abs(s[fx]-s[fy]));
				printf("%d\n",d[x]-d[fx]+d[y]-d[fy]+t);
			}
		}
	}
	while(1);
}
