#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<vector>
#define fr(i,n) for(int i=0;i<n;i++)
using namespace std;
int a[20020][3];
int c[105],h[105],tot;
int n,m,mx;
double e[105][105];
double ans;
void add(int x,int y,int z)
{
	tot++;
	c[x]++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	a[tot][2]=z;
	h[x]=tot;
}
double solve()
{
	double m;
	for(int i=1;i<n;i++)
	{
		int j,k=i;
		for(j=i+1;j<n;j++)
			if(fabs(e[j][i])>fabs(e[k][i]))
				k=j;
		for(j=1;j<=n+1;j++)
			swap(e[i][j],e[k][j]);
		for(j=1;j<=n;j++)
			if(j!=i)
			{
				m=e[j][i]/e[i][i];
				for(k=i;k<=n+1;k++)
					e[j][k]-=m*e[i][k];
			}
	}
	return e[1][n+1]/e[1][1];
}
int main()
{
	scanf("%d %d",&n,&m);
	fr(i,m)
	{
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		add(x,y,z);
		if(x!=y)
			add(y,x,z);
		mx=max(mx,z);
	}
	fr(i,31)
	{
		memset(e,0,sizeof e);
		for(int j=1;j<=n;j++)
			e[j][j]=1;
		for(int j=1;j<n;j++)
		{
			for(int k=h[j];k;k=a[k][0])
				if((a[k][2]>>i)&1)
				{
					e[j][a[k][1]]+=1.0/c[j];
					e[j][n+1]+=1.0/c[j];
				}
				else
					e[j][a[k][1]]-=1.0/c[j];
		}
		ans+=solve()*(1<<i);
	}
	printf("%.3f",ans);
	return 0;
}
