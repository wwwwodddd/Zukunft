#include<stdio.h>
#include<string.h>
int n,m,x;
long long f[12][12];
long long c[12][12];
int main()
{
	for(int i=0;i<12;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)
			c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
	while(~scanf("%d %d",&n,&m))
	{
		memset(f,0,sizeof f);
		f[0][0]=1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			for(int j=0;j<=m;j++)
				for(int k=0;k<=j&&k<=x;k++)
					f[i][j]+=f[i-1][j-k]*c[j][k];
		}
		printf("%I64d\n",f[n][m]);
	}
	return 0;
}
