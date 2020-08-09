#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
#define inf 0x3f3f3f3f
using namespace std;
int a[500020][3];
int h[60020];
int v[60020];
int n,m,s,t,r,c;
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
int i,j,k,l,d,ans,dd;
char f[30][30],g[30][30];
int main()
{
	scanf("%d %d %d",&r,&c,&d);
	tot=1;
	s=r*c*2+1;
	t=r*c*2+2;
	for(i=0;i<r;i++)
		scanf("%s",f[i]);
	for(i=0;i<r;i++)
		scanf("%s",g[i]);
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			if(i<d||j<d||i>=r-d||j>=c-d)
				add(i*c+j,t,inf);
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			if(g[i][j]=='L')
				add(s,r*c+i*c+j,1),ans++;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			if(f[i][j]-'0')
				add(r*c+i*c+j,i*c+j,f[i][j]-'0');
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			for(k=0;k<r;k++)
				for(l=0;l<c;l++)
					if((i-k)*(i-k)+(l-j)*(l-j)<=d*d)
						add(i*c+j,r*c+k*c+l,inf);
	while(bfs())
		while(dd=dinic(s,inf))
			ans-=dd;
	printf("%d",ans);
	return 0;
}