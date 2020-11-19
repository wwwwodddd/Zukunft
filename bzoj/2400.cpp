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
int n,m,l,s,t,ans,kk,x;
int h[520];
int v[520];
int w[520];
int f[520];
int a[2000020][3],tot;
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
	memset(v,0,sizeof v);
	v[s]=1;
	queue<int>q;
	q.push(s);
	while(q.size())
	{
		int u=q.front();
		q.pop();
		for(int i=h[u];i;i=a[i][0])
			if(a[i][2]&&!v[a[i][1]])
			{
				v[a[i][1]]=v[u]+1;
				q.push(a[i][1]);
				if(a[i][1]==t)
					return 1;
			}
	}
	return 0;
}
int dfs(int x,int y)
{
	if(x==t)
		return y;
	int u=0;
	for(int i=h[x];i;i=a[i][0])
		if(u<y&&a[i][2]&&v[a[i][1]]==v[x]+1)
		{
			int k=dfs(a[i][1],min(a[i][2],y-u));
			if(!k)
				v[a[i][1]]=0;
			a[i][2]-=k;
			a[i^1][2]+=k;
			u+=k;
		}
	return u;
}
void mk(int x,int o)
{
	w[x]|=1<<o;
	if(v[x])
		return;
	v[x]=1;
	for(int i=h[x];i;i=a[i][0])
		if(i%2==0&&a[i][2])
			mk(a[i][1],o);
}
int e[3020][2];
void work()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
		scanf("%d %d",&e[i][0],&e[i][1]);
	scanf("%d",&l);
	memset(f,0,sizeof f);
	memset(w,0,sizeof w);
	for(int i=0;i<l;i++)
		scanf("%d",&x),scanf("%d",w+x),f[x]=1;
	s=0,t=n+1;
	ans=0;
	for(int b=31;b--;)
	{
		memset(h,0,sizeof h);
		tot=1;
		for(int i=1;i<=n;i++)
			if(f[i])
				if(w[i]>>b&1)
					add(s,i,0xffff);
				else
					add(i,t,0xffff);
		for(int i=0;i<m;i++)
		{
			add(e[i][0],e[i][1],1);
			add(e[i][1],e[i][0],1);
		}
		while(bfs())
			while(kk=dfs(s,0xffff))
				ans+=kk<<b;
		memset(v,0,sizeof v);
		mk(s,b);
	}
	for(int i=1;i<=n;i++)
		printf("%d\n",w[i]);
}
int main()
{
	int t;
	for(scanf("%d",&t);t--;)
		work();
	return 0;
}
