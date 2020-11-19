#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int n,m,i,j,k;
int a[3][120];
int f[120][6][15];
int g[120][15];
int main()
{
	scanf("%d %d %d",&n,&m,&k);
	memset(a,0xfe,sizeof(a));
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[j][i]);
	memset(f,0xcc,sizeof(f));
	memset(g,0xcc,sizeof(g));
	f[0][0][0]=0;
	g[0][0]=0;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=k;j++)
			f[i][0][j]=g[i-1][j];
		for(j=1;j<=k;j++)
		{
			f[i][1][j]=max(g[i-1][j-1],max(f[i-1][1][j],f[i-1][4][j]))+a[1][i];
			f[i][2][j]=max(g[i-1][j-1],max(f[i-1][2][j],f[i-1][4][j]))+a[2][i];
		}
		for(j=1;j<=k;j++)
			f[i][3][j]=max(g[i-1][j-1],f[i-1][3][j])+a[1][i]+a[2][i];
		for(j=2;j<=k;j++)
			f[i][4][j]=max(g[i-1][j-2],max(max(f[i-1][1][j-1],f[i-1][2][j-1]),f[i-1][4][j]))+a[1][i]+a[2][i];
		for(j=0;j<=k;j++)
			g[i][j]=max(f[i][0][j],max(max(f[i][1][j],f[i][2][j]),max(f[i][3][j],f[i][4][j])));
	}
	printf("%d",g[n][k]);
}