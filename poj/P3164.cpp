#include<stdio.h>
#include<string.h>
#include<iostream>
#include<math.h>
using namespace std;
int v[120],c[120],p[120];
double d[120][120];
double x[120],y[120];
int n;
void dfs(int x)
{
	if(v[x])
		return;
	v[x]=1;
	for(int i=1;i<=n;i++)
		if(d[x][i]<1E30)
			dfs(i);
}
int ok()
{
	dfs(1);
	for(int i=1;i<=n;i++)
		if(!v[i])
			return 0;
	return 1;
}
double work()
{
	double re=0;
	p[1]=1;
	memset(c,0,sizeof c);
	for(;;)
	{
		int i;
		for(i=2;i<=n;i++)
		{
			if(c[i])
				continue;
			d[i][i]=1E30;
			p[i]=i;
			for(int j=1;j<=n;j++)
			{
				if(c[j])
					continue;
				if(d[j][i]<d[p[i]][i])
					p[i]=j;
			}
		}
		for(i=2;i<=n;i++)
		{
			if(c[i])
				continue;
			int j;
			memset(v,0,sizeof v);
			for(j=i;!v[j];j=p[j])
				v[j]=1;
			if(j==1)
				continue;
			i=j;
			re+=d[p[i]][i];
			for(j=p[i];j!=i;j=p[j])
				re+=d[p[j]][j],c[j]=1;
			j=i;
			do
			{
				for(int k=1;k<=n;k++)
				{
					if(c[k])
						continue;
					d[i][k]=min(d[i][k],d[j][k]);
					d[k][i]=min(d[k][i],d[k][j]-d[p[j]][j]);
				}
				j=p[j];
			}
			while(j!=i);	
			break;
		}
		if(i>n)
		{
			for(int j=2;j<=n;j++)
			{
				if(c[j])
					continue;
				re+=d[p[j]][j];	
			}
			break;
		}
	}
	return re;
}
double dis(int i,int j)
{
	return hypot(x[i]-x[j],y[i]-y[j]);
}
int main()
{
	int m;
	while(scanf("%d %d",&n,&m)+1)
	{
		for(int i=1;i<=n;i++)
			scanf("%lf %lf",x+i,y+i);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				d[i][j]=1E30;
		for(int i=0;i<m;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			d[x][y]=dis(x,y);
		}
		memset(v,0,sizeof v);
		if(!ok())
			puts("poor snoopy");
		else
			printf("%.2f\n",work());
	}
	return 0;
}
