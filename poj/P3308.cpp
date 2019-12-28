#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#define INF 0x3fffffff
using namespace std;
int d[105],csc;
double g[105][105];
int c[105];
int p[105];
int n,m;
double log2(double x)
{
	return log(x)/log(2.0);
}
double isap(int s,int t)
{
	int i=s,j;
	double re=0,z;
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
int i,j,k,x,y,z,M,N,L,ans;
double w;
int main()
{
	scanf("%d",&csc);
	while(csc--)
	{
		scanf("%d %d %d",&M,&N,&L);
		m=M+N+2;
		memset(g,0,sizeof(g));
		for(i=1;i<=M;i++)
		{
			scanf("%lf",&w);
			g[0][i]=log2(w);
		}
		for(i=1;i<=N;i++)
		{
			scanf("%lf",&w);
			g[M+i][m-1]=log2(w);
		}
		for(i=1;i<=L;i++)
		{
			scanf("%d %d",&x,&y);
			g[x][y+M]=100;
		}
		memset(d,0,sizeof(d));
		memset(c,0,sizeof(c));
		printf("%.4lf\n",pow(2,isap(0,m-1)));
	}
	return 0;
}