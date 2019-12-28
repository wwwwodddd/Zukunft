#include<stdio.h>
#include<string.h>
int i,j,k,l,t,n,m;
int dp[105][105];
int a[105],b[105];
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(i=1;i<=m;i++)
			scanf("%d",&b[i]);
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
			{
			dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
			if(a[i]==b[j])
				continue;
			for(k=i-1;k>0;k--)
				if(a[k]==b[j])
					break;
			for(l=j-1;l>0;l--)
				if(b[l]==a[i])
					break;
			if(k&&l)
				dp[i][j]=max(dp[i][j],dp[k-1][l-1]+2);
			}
		printf("%d\n",dp[n][m]);
	}
	return 0;
}
