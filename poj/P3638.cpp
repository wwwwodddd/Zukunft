#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int n,m,t,a[220];
double f[220][220];
double g[220][220];
int main()
{
	for(scanf("%d",&t);t--;)
	{
		memset(g,0,sizeof g);
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
			{
				if(i==j)
					g[i][j]=0;
				else
				{
					double rt=(double)(a[j]-a[i])/(j-i);
					for(int k=i+1;k<j;k++)
						g[i][j]+=fabs(rt*(k-i)+a[i]-a[k]);
				}	
			}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				f[i][j]=1e30;
		for(int i=2;i<=n;i++)
			for(int j=2;j<=m;j++)
			{
				if(j==2)
					f[i][j]=g[1][i];
				else
					for(int k=2;k<i;k++)
						f[i][j]=min(f[i][j],f[k][j-1]+g[k][i]);
			}
		printf("%.4f\n",f[n][m]/n);
	}
}
