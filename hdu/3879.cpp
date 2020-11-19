#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
using namespace std;
int a[400020][3],tot;
int h[60000],sm;
int v[60000];
int n,m,s,t,x,y,z,kk;
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
	queue<int>q;
	v[s]=1;
	q.push(s);
	while(q.size())
	{
		int u=q.front();
		q.pop();
		for(int i=h[u];i;i=a[i][0])
			if(a[i][2]&&!v[a[i][1]])
			{
				v[a[i][1]]=v[u]+1;
				if(a[i][1]==t)
					return 1;
				q.push(a[i][1]);
			}
	}
	return 0;
}
int dfs(int x,int y)
{
	if(x==t)
		return y;
	int u=y;
	for(int i=h[x];i;i=a[i][0])
		if(u&&a[i][2]&&v[a[i][1]]==v[x]+1)
		{
			int k=dfs(a[i][1],min(u,a[i][2]));
			if(!k)
				v[a[i][1]]=0;
			u-=k;
			a[i][2]-=k;
			a[i^1][2]+=k;
		}
	return y-u;
}
int main()
{
	while(~scanf("%d %d",&n,&m))
	{
		memset(h,0,sizeof h);
		tot=1;
		sm=0;
		s=0,t=n+m+1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			add(s,i,x);
		}
		for(int i=n+1;i<=n+m;i++)
		{
			scanf("%d %d %d",&x,&y,&z);
			add(x,i,0xfffffff);
			add(y,i,0xfffffff);
			add(i,t,z);
			sm+=z;
		}
		while(bfs())
			while(kk=dfs(s,0x7fffffff))
				sm-=kk;
		printf("%d\n",sm);
	}
	return 0;
}
