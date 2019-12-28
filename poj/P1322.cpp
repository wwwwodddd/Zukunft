#include<stdio.h>
#include<string.h>
double dp[2][110];
int n,m,c;
int main()
{
	int i,j,k;
	while(scanf("%d %d %d",&c,&n,&m)&&c)
	{
		if(m>c||m>n||(m+n)%2)
		{
			printf("%.3lf\n",0);
			continue;
		}
		memset(dp,0,sizeof(dp));
		n>1000?n=1000+n%2:0;
		dp[0][0]=dp[1][1]=1;
		for(i=2;i<=n;i++)
			for(j=0;j<=c;j++)
				dp[i&1][j]=(j>0?dp[1&i^1][j-1]*(c-j+1)/c:0)+dp[1&i^1][j+1]*(j+1)/c;
		printf("%.3lf\n",dp[n&1][m]);
	}
	return 0;
}
