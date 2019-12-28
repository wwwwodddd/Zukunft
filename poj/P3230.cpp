#include<stdio.h>
#include<string.h>
int n,m;
int g[105][105];
int c[105][105];
int f[105][105];
int i,j,k;
int ans;
int max(int x,int y)
{
	return x>y?x:y;
}
int main()
{
	while(scanf("%d %d",&n,&m)&&n+m)
	{
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				scanf("%d",&g[i][j]);
		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++)
				scanf("%d",&c[i][j]);
		memset(f,0x80,sizeof(f));
		f[0][1]=0;
		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++)
				for(k=1;k<=n;k++)
					f[i][j]=max(f[i][j],f[i-1][k]-g[k][j]+c[i][j]);
		ans=f[m][1];
		for(i=2;i<=n;i++)
			ans=max(ans,f[m][i]);
		printf("%d\n",ans);
	}
	return 0;
}