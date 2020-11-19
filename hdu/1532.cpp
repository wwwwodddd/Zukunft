#include<stdio.h>
#include<queue>
#include<iostream>
using namespace std;
int a[200020][3],tot;
int h[220];
int v[220];
int s,t,n,m;
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
	int i,p;
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
	int i,u=y,k;
	if(x==t)
		return y;
	for(i=h[x];i;i=a[i][0])
	{
		if(u&&a[i][2]&&v[a[i][1]]==v[x]+1)
		{
			k=dinic(a[i][1],min(u,a[i][2]));
			if(k==0)
				v[a[i][1]]=0;
			u-=k;
			a[i][2]-=k;
			a[i^1][2]-=k;
		}
	}
	return y-u;
}
int main()
{
	int i,x,y,z,ans,dd;
	while(scanf("%d %d",&m,&n)+1)
	{
		tot=1;
		ans=0;
		memset(h,0,sizeof(h));
		for(i=0;i<m;i++)
		{
			scanf("%d %d %d",&x,&y,&z);
			add(x,y,z);
		}
		s=1;
		t=n;
		while(bfs())
			while(dd=dinic(s,0x3f3f3f3f))
				ans+=dd;
		printf("%d\n",ans);
	}
	return 0;
}