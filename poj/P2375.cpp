#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int dfn[250020],low[250020];
int a[600000][2];
int h[250020],tot;
int cnt,ss;
int s[250020];
int v[250020];
int r[250020];
int ao,ai,scc,n,m,x,y,aa;
int ans[250020];
int out[250020],in[250020];
int g[505][505];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int dir[4][2]={1,0,0,1};
void add(int x,int y)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	h[x]=tot;
}
void tarjan(int x)
{
	int y,i,j;
	cnt++;
	dfn[x]=low[x]=cnt;
	v[x]=1;
	s[ss++]=x;
	for(i=h[x];i;i=a[i][0])
	{
		if(dfn[a[i][1]]==0)
		{
			tarjan(a[i][1]);
			if(low[x]>low[a[i][1]])
				low[x]=low[a[i][1]];
		}
		else if(v[a[i][1]]==1&&low[x]>dfn[a[i][1]])
			low[x]=dfn[a[i][1]];
	}
	if(dfn[x]==low[x])
	{
		scc++;
		do
		{
			y=s[--ss];
			r[y]=scc;
			v[y]=0;
		}
		while(x!=y);
	}
}
int main()
{
	int i,j,k,nx,ny,p,q;
	scanf("%d%d",&m,&n);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&g[i][j]);
	cnt=1;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			p=i*m+j;
			for(k=0;k<2;k++)
			{
				nx=i+dir[k][0];
				ny=j+dir[k][1];
				if(nx<0||nx>=n||ny<0||ny>=m)continue;
				q=nx*m+ny;
				if(g[i][j]>=g[nx][ny])
					add(p,q);
				if(g[i][j]<=g[nx][ny])
					add(q,p);
			}
		}
	for(i=0;i<n*m;i++)
		if(dfn[i]==0)
			tarjan(i);
	for(i=0;i<n*m;i++)
	{
		for(j=h[i];j;j=a[j][0])
		{
			if(r[i]==r[a[j][1]])
				continue;
			in[r[a[j][1]]]++;
			out[r[i]]++;
		}
	}
	if(scc==1)
	{
		puts("0");
		return 0;
	}
	for(i=1;i<=scc;i++)
	{
		if(out[i]==0)
			ao++;
		if(in[i]==0)
			ai++;
	}
	printf("%d\n",max(ai,ao));
	return 0;
}