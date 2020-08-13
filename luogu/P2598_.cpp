#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int n,m,s,t;
int a[200020][3];
int h[10020],tot;
int v[10020];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
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
	a[tot][2]=z;
	h[y]=tot;
}
int bfs()
{
	int now,p,i;
	memset(v,0,sizeof v);
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
int dinic(int x,int y)
{
	int u=y,k,i;
	if(x==t)
		return y;
	for(i=h[x];i;i=a[i][0])
	{
		if(u&&a[i][2]&&v[a[i][1]]==v[x]+1)
		{
			k=dinic(a[i][1],min(a[i][2],u));
			if(!k)
				v[a[i][1]]=0;
			u-=k;
			a[i][2]-=k;
			a[i^1][2]+=k;
		}
	}
	return y-u;
}
int main()
{
	scanf("%d%d",&n,&m);
	tot=1;
	s=n*m;
	t=s+1;
	for(int i=0;i<n;i++)
		for(int j=1;j<m;j++)
			add(i*m+j-1,i*m+j,1);
	for(int i=1;i<n;i++)
		for(int j=0;j<m;j++)
			add(i*m+j-m,i*m+j,1);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			int k;
			scanf("%d",&k);
			if(k)
				add(i*m+j,k==1?s:t,0xffff);
		}
	int ans=0;
	while(bfs())
		while(int dd=dinic(s,inf))
			ans+=dd;
	printf("%d\n",ans);
	return 0;
}