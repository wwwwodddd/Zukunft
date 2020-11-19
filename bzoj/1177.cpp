#include<iostream>
#include<stdio.h>
using namespace std;
int e[1600][1600],f[1600][1600],g[1600][1600],h[1600][1600],o[1600][1600],s[1600][1600],c[1600],r[1600],a[1600][1600];
int n,m,k,i,j,ans=0;
int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			o[i][j]=o[i-1][j]+o[i][j-1]-o[i-1][j-1]+a[i][j];
	for(i=k;i<=n;i++)
		for(j=k;j<=m;j++)
		{
			s[i][j]=o[i][j]-o[i-k][j]-o[i][j-k]+o[i-k][j-k];
			c[i]=max(c[i],s[i][j]);
			r[j]=max(r[j],s[i][j]);
		}
	for(i=k;i<=n;i++)
	{
		for(j=k;j<=m;j++)
			e[i][j]=max(s[i][j],max(e[i-1][j],e[i][j-1]));
		for(j=m-k+1;j>=1;j--)
			f[i][j]=max(s[i][j+k-1],max(f[i-1][j],f[i][j+1]));
	}
	for(i=m-k+1;i>=1;i--)
	{
		for(j=k;j<=m;j++)
			g[i][j]=max(s[i+k-1][j],max(g[i+1][j],g[i][j-1]));
		for(j=m-k+1;j>=1;j--)
			h[i][j]=max(s[i+k-1][j+k-1],max(h[i+1][j],h[i][j+1]));
	}
	for(i=k;i<=n-k;i++)
		for(j=k;j<=m-k;j++)
			ans=max(ans,max(e[i][j]+f[i][j+1]+h[i+1][j],e[i][m]+g[i+1][j]+h[i+1][j+1]));
	for(i=k;i<=n-k;i++)
		for(j=k;j<=m-k;j++)
			ans=max(ans,max(g[i][j]+f[i][j+1]+h[i+1][j+1],e[i][j]+g[i+1][j]+f[n][j+1]));
	for(i=k;i<=n-2*k;i++)
		for(j=i+k;j<=n-k;j++)
			ans=max(ans,f[i][1]+c[j]+g[j+1][m]);
	for(j=k;j<=m-2*k;j++)
		for(i=j+k;i<=n-k;i++)
			ans=max(ans,e[n][j]+r[i]+h[1][i+1]);
	printf("%d\n",ans);
	return 0;
}