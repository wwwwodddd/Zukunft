#include<iostream>
#define inf 0xffffff
using namespace std;
int d[220];
int r[220][220],sum,ssum;
int g[220][220];
int c[220];
int p[220];
int v[220];
int n,m;
int ll,rr;
int isap(int s,int t)
{
	int i=s,j;
	int re=0,z;
	c[0]=m;
	memset(p,-1,sizeof(p));
	p[s]=s;
	while(d[s]<m)
	{
		for(j=0;j<m;j++)
			if(g[i][j]>0&&d[i]==d[j]+1)
				break;
		if(j<m)
		{
			p[j]=i;
			i=j;
			if(i==t)
			{
				z=0x7fffffff;
				for(i=t;i!=s;i=p[i])
					z=min(z,g[p[i]][i]);
				for(i=t;i!=s;i=p[i])
					g[p[i]][i]-=z,g[i][p[i]]+=z;
				re+=z;
			}
		}
		else
		{
			c[d[i]]--;
			if(c[d[i]]==0)
				return re;
			d[i]=m;
			for(j=0;j<m;j++)
				if(g[i][j]>0)
					d[i]=min(d[i],d[j]+1);
			c[d[i]]++;
			i=p[i];
		}
	}
	return re;
}
int i,j,k,w,x,y,z,M,N,ans;
void dfs(int x)
{
	v[x]=1;
	for(int i=1;i<=m;i++)
		if(g[x][i]&&!v[i])
			dfs(i);
	return;
}
int main()
{
	scanf("%d %d",&M,&N);
	m=2*M+2;
	for(i=1;i<=M;i++)
	{
		scanf("%d",&w);
		g[M+i][m-1]=w;
		g[m-1][M+i]=0;
	}
	for(i=1;i<=M;i++)
	{
		scanf("%d",&w);
		g[0][i]=w;
		g[i][0]=0;
	}
	for(i=1;i<=N;i++)
	{
		scanf("%d %d",&x,&y);
		g[x][y+M]=inf;
		g[y+M][x]=0;
	}
	printf("%d\n",isap(0,m-1));
	dfs(0);
	for(i=1;i<=M;i++)
	{
		if(v[i+M])
			ans++;
		if(!v[i])
			ans++;
	}
	printf("%d\n",ans);
	for(i=1;i<=M;i++)
	{
		if(v[i+M])
			printf("%d +\n",i);
		if(!v[i])
			printf("%d -\n",i); 
	}
	return 0;
}