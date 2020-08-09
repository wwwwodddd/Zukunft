#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int a[500020][3];
int h[60020];
int v[60020];
int n,m,s,t;
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
int main()
{
	scanf("%d%d",&n,&m);
	tot=1;
	s=0;
	t=n+1;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		if(x>0)
		{
			ans+=x;
			add(s,i,x);
		}
		else
			add(i,t,-x);
	}
	for(int i=0;i<m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
	}
	while(bfs())
		while(int dd=dinic(s,inf))
			ans-=dd;
	printf("%d\n",ans);
	return 0;
}