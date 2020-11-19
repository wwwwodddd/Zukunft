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
int n,m,s,t;
long long ans,kk;
long long inf=1LL<<60,dt=1LL<<50;
int h[1020],tot;
int v[1020];
struct V
{
	int x,y;
	long long z;
}a[2000020];
long long A[1020];
long long E[1020][1020];
void add(int x,int y,long long z,long long rz=0)
{
	tot++;
	a[tot].x=h[x];
	a[tot].y=y;
	a[tot].z=z;
	h[x]=tot;

	tot++;
	a[tot].x=h[y];
	a[tot].y=x;
	a[tot].z=rz;
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
		for(int i=h[u];i;i=a[i].x)
			if(a[i].z&&!v[a[i].y])
			{
				v[a[i].y]=v[u]+1;
				q.push(a[i].y);
				if(a[i].y==t)
					return 1;
			}
	}
	return 0;
}
long long dfs(int x,long long y)
{
	if(x==t)
		return y;
	long long u=0;
	for(int i=h[x];i;i=a[i].x)
		if(u<y&&a[i].z&&v[a[i].y]==v[x]+1)
		{
			long long k=dfs(a[i].y,min(a[i].z,y-u));
			if(!k)
				v[a[i].y]=0;
			a[i].z-=k;
			a[i^1].z+=k;
			u+=k;
		}
	return u;
}
int main()
{
	tot=1;
	scanf("%d",&n);
	s=n,t=s+1;
	for(int i=0;i<n;i++)
		scanf("%lld",A+i);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%lld",E[i]+j);
	for(int i=0;i<n;i++)
	{
		long long w=A[i];
		for(int j=0;j<n;j++)
		{
			if(i<j)
				add(i,j,2*E[i][j],2*E[i][j]);
			w-=E[i][j];
		}
		add(s,i,dt);
		add(i,t,w+dt);
	}
	while(bfs())
		while(kk=dfs(s,inf))
			ans+=kk;
	printf("%lld",n*dt-ans);
	return 0;
}
