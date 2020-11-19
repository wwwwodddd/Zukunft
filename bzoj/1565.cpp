#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
int a[500020][3];
int h[620];
int v[620];
int in[620];
int w[35][35];
int n,m,s,t,l,x,y,sm,tot;
void add(int x,int y,int z)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	a[tot][2]=z;
	h[x]=tot;
	if(z==0xffffff)
		in[y]++;
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
			if(!in[a[i][1]]&&!v[a[i][1]]&&a[i][2])
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
	scanf("%d %d",&n,&m);
	tot=1;
	s=n*m;
	t=s+1;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			scanf("%d",w[i]+j);
			if(w[i][j]>0)
				add(i*m+j,t,w[i][j]);
			else if(w[i][j]<0)
				add(s,i*m+j,-w[i][j]);
			scanf("%d",&l);
			for(int k=0;k<l;k++)
			{
				scanf("%d %d",&x,&y);
				add(i*m+j,x*m+y,0xffffff);
			}
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<m-1;j++)
			add(i*m+j+1,i*m+j,0xffffff);
	queue<int>q;
	for(int i=0;i<n*m;i++)
		if(!in[i])
			q.push(i);
	for(;q.size();q.pop())
		for(int i=h[q.front()];i;i=a[i][0])
			if(a[i][2]==0xffffff&&!--in[a[i][1]])
				q.push(a[i][1]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(!in[i*m+j]&&w[i][j]>0)
				sm+=w[i][j];
	while(bfs())
		while(int dd=dinic(s,0x3f3f3f3f))
			sm-=dd;
	printf("%d",sm);
	return 0;
}
