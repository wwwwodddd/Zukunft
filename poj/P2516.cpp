#include<stdio.h>
#include<string.h>
#include<iostream>
#define inf 0x3f3f3f3f
using namespace std;
int c[110][110];
int g[110][110];
int d[110];
int v[110];
int p[110];
int q[300000],b,f;
int ans;
int n,m;
int spfa(int s,int t)
{
	int u,i;
	memset(d,0x3f,sizeof(d));
	memset(v,0,sizeof(v));
	d[s]=0;
	v[s]=1;
	b=f=0;
	q[f++]=s;
	while(b<f)
	{
		u=q[b++];
		v[u]=0;
		for(i=s;i<=t;i++)
			if(g[u][i]>0&&d[i]>d[u]+c[u][i])
			{
				d[i]=d[u]+c[u][i];
				p[i]=u;
				if(!v[i])
				{
					q[f++]=i;
					v[i]=1;
				}
			}
	}
	return d[t]!=inf;
}
void ek(int s,int t)
{
	int u;
	int a=inf;
	for(u=t;u!=s;u=p[u])
		a=min(a,g[p[u]][u]);
	for(u=t;u!=s;u=p[u])
	{
		g[p[u]][u]-=a,g[u][p[u]]+=a;
		ans+=c[p[u]][u]*a;
	}
}
int nd[110][110];
int nt[110];
int hv[110][110];
int ht[110];
int poj;
int main()
{
	int i,j,k,t;
	while(scanf("%d %d %d",&n,&m,&k),n)
	{
		ans=0;
		memset(nt,0,sizeof(nt));
		memset(ht,0,sizeof(ht));
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=k;j++)
			{
				scanf("%d",&nd[i][j]);
				nt[j]+=nd[i][j];
			}
		}
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=k;j++)
			{
				scanf("%d",&hv[i][j]);
				ht[j]+=hv[i][j];
			}
		}
		poj=1;
		for(i=1;i<=k;i++)
			if(nt[i]>ht[i])
				break;
		if(i<=k)
			poj=0;
		for(i=1;i<=k;i++)
		{
			memset(g,0,sizeof(g));
			memset(c,0,sizeof(c));
			for(j=1;j<=n;j++)
			{
				for(t=1;t<=m;t++)
				{
					cin>>c[t][j+m];
					c[j+m][t]=-c[t][j+m];
					g[t][j+m]=inf;
				}
			}
			if(!poj)
				continue;
			for(j=1;j<=m;j++)
			{
				g[0][j]=hv[j][i];
				c[0][j]=c[j][0]=0;
			}
			for(j=1;j<=n;j++)
			{
				g[m+j][m+n+1]=nd[j][i];
				c[m+j][m+n+1]=c[m+n+1][m+j]=0;
			}
			while(spfa(0,n+m+1))
				ek(0,n+m+1);
		}
		printf("%d\n",poj?ans:-1);
	}
	return 0;
}