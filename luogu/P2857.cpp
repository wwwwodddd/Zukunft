#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int a[500020][3];
int h[60020];
int v[60020];
int n,m,l,s,t;
int tot;
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
int b[1020][21];
int c[21];
bool work(int l,int r)
{
	memset(h,0,sizeof h);
	tot=1;
	s=0;
	t=n+m+1;
	for(int i=1;i<=n;i++)
	{
		add(s,i,1);
		for(int j=l;j<r;j++)
			add(i,n+b[i][j],1);
	}
	for(int i=1;i<=m;i++)
		add(n+i,t,c[i]);
	int ans=0;
	while(bfs())
		while(int dd=dinic(s,inf))
			ans+=dd;
	return ans==n;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&b[i][j]);
	for(int i=1;i<=m;i++)
		scanf("%d",&c[i]);
	int ans=m;
	for (int i=0,j=0;i<m;i++)
	{
		while(j<m&&!work(i,j))
			j++;
		if(work(i,j))
			ans=min(ans,j-i);
	}
	printf("%d\n",ans);
	return 0;
}