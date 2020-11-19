#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int n,m,x,y,z,ans,s,t;
int e[400020][3],ee;
int g[1020];
void add(int x,int y,int z)
{
	ee++;
	e[ee][0]=g[x];
	e[ee][1]=y;
	e[ee][2]=z;
	g[x]=ee;
}
void init()
{
	ee=0;
	memset(g,0,sizeof g);
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		add(x,y,z);
	}
	scanf("%d %d",&s,&t);
}
namespace NW
{
	int a[400020][3];
	int h[1020],tot;
	int v[1020];
	void clr()
	{
		tot=1;
		memset(h,0,sizeof h);
		ans=0;
	}
	void add(int x,int y,int z)
	{
		tot++;
		a[tot][0]=h[x];
		a[tot][1]=y;
		a[tot][2]=z;
		h[x]=tot;

		tot++;
		a[tot][0]=h[y];
		a[tot][1]=x;
		a[tot][2]=0;
		h[y]=tot;
	}
	int bfs()
	{
		int now,p,i;
		memset(v,0,sizeof(v));
		v[s]=1;
		queue<int>q;
		q.push(s);
		while(q.size())
		{
			now=q.front();
			q.pop();
			for(i=h[now];i;i=a[i][0])
			{
				if(!v[a[i][1]]&&a[i][2])
				{
					v[a[i][1]]=v[now]+1;
					q.push(a[i][1]);
					if(a[i][1]==t)
						return 1;
				}
			}
		}
		return 0;
	}
	int dfs(int x,int y)
	{
		int u=y,k,i;
		if(x==t)
			return y;
		for(i=h[x];i;i=a[i][0])
		{
			if(u&&a[i][2]&&v[a[i][1]]==v[x]+1)
			{
				k=dfs(a[i][1],min(a[i][2],u));
				if(!k)
					v[a[i][1]]=0;
				u-=k;
				a[i][2]-=k;
				a[i^1][2]+=k;
			}
		}
		return y-u;
	}
	void work()
	{
		int dd;
		while(bfs())
			while(dd=dfs(s,0x3f3f3f3f))
				ans+=dd;
		printf("%d\n",ans);
	}
}
namespace DIJK
{
	int d[1020];
	int v[1020];
	void mk()
	{
		NW::clr();
		for(int i=1;i<=n;i++)
			for(int j=g[i];j;j=e[j][0])
				if(d[i]+e[j][2]==d[e[j][1]])
					NW::add(i,e[j][1],1);
	}
	void work()
	{
		memset(d,0x33,sizeof d);
		memset(v,0,sizeof v);
		d[s]=0;
		for(int i=0;i<n;i++)
		{
			y=0x3f3f3f3f;
			for(int j=1;j<=n;j++)
				if(!v[j]&&d[j]<y)
					y=d[x=j];
			v[x]=1;
			for(int j=g[x];j;j=e[j][0])
				d[e[j][1]]=min(d[e[j][1]],d[x]+e[j][2]);
		}
		mk();
	}
}
int main()
{
	int t;
	for(scanf("%d",&t);t--;)
	{
		init();
		DIJK::work();
		NW::work();
	}
	return 0;
}
