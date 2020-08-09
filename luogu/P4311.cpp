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
int b[120][120];
int r[120];
int c[120];
void work()
{
	for(int i=1;i<=n;i++)
	{
		if(r[i]<0)
		{
			printf("JIONG!\n");
			return;
		}
		add(s,i,r[i]);
	}
	for(int i=1;i<=m;i++)
	{
		if(c[i]<0)
		{
			printf("JIONG!\n");
			return;
		}
		add(n+i,t,c[i]);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!b[i][j])
				add(i,n+j,1);
	int ans=n*m-l;
	while(bfs())
		while(int dd=dinic(s,inf))
			ans-=dd;
	printf("%d\n",ans);
	return;
}
int main()
{
	scanf("%d%d%d",&n,&m,&l);
	tot=1;
	s=0;
	t=n+m+1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&r[i]);
		r[i]=m-r[i];
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&c[i]);
		c[i]=n-c[i];
	}
	for(int i=0;i<l;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		b[x][y]=1;
		r[x]--;
		c[y]--;
	}
	work();
	return 0;
}