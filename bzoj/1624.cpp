#include<stdio.h>
#include<iostream>
using namespace std;
int n,m,i,j,k;
int a[10020];
int g[105][105];
int ans;
int main()
{
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&g[i][j]);
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	for(i=1;i<m;i++)
		ans+=g[a[i-1]][a[i]];
	printf("%d",ans);
	return 0;
}