#include<stdio.h>
#include<string.h>
long long f[51][51];
int n,m,t;
int i,j,k,x;
int c[51];
int main()
{
	while(scanf("%d %d",&n,&m)&&n+m)
	{
		memset(c,0,sizeof(c));
		memset(f,0,sizeof(f));
		t++;
		printf("Case %d:\n",t);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			c[x]++;
		}
		for(i=1;i<=n;i++)
			f[i][0]=1;
		for(i=1;i<=c[1];i++)
			f[1][i]=1;
		for(i=2;i<=n;i++)
			for(j=1;j<=n;j++)
				for(k=0;k<=j&&k<=c[i];k++)
					f[i][j]+=f[i-1][j-k];
		for(i=1;i<=m;i++)
		{
			scanf("%d",&x);
			printf("%I64d\n",f[n][x]);
		}
	}
	return 0;
}
