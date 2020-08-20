#include <bits/stdc++.h>
using namespace std;
int n,m,s,t;
int a[500020][3];
int h[60020],tot;
int v[60020];
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
	a[tot][2]=0;
	h[y]=tot;
}
int bfs()
{
	int p,i;
	memset(v,0,sizeof(v));
	queue<int>q;
	q.push(s);
	v[s]=1;
	while(q.size())
	{
		p=q.front();
		q.pop();
		for(i=h[p];i;i=a[i][0])
			if(a[i][2]&&!v[a[i][1]])
			{
				v[a[i][1]]=v[p]+1;
				if(a[i][1]==t)
					return 1;
				q.push(a[i][1]);
			}
	}
	return 0;
}
int dinic(int x,int y)
{
	int u=y,i,k;
	if(x==t)
		return y;
	for(i=h[x];i;i=a[i][0])
		if(u&&a[i][2]&&v[a[i][1]]==v[x]+1)
		{
			k=dinic(a[i][1],min(a[i][2],u));
			if(k==0)
				v[a[i][1]]=0;
			u-=k;
			a[i][2]-=k;
			a[i^1][2]+=k;
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
		for(int j=0;j<m;j++)
			for(int k=0;k<4;k++)
				if((i+j)&1)
					if(i+dx[k]>=0&&i+dx[k]<n&&j+dy[k]>=0&&j+dy[k]<m)
						add(i*m+j,(i+dx[k])*m+j+dy[k],0x3f3f3f3f);
	int ans=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			int x;
			scanf("%d",&x);
			ans+=x;
			if((i+j)&1)
				add(s,i*m+j,x);
			else
				add(i*m+j,t,x);
		}
	while(bfs())
		while(int dd=dinic(s,0x3f3f3f3f))
			ans-=dd;
	printf("%d\n",ans);
	return 0;
}