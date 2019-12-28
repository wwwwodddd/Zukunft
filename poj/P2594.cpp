#include <stdio.h>
#include <string.h>
int a[510][510],t[510],c[510];
int n,ans;
void floyd()
{
int i,j,k;
for(k=1;k<=n;k++)
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(a[i][k]+a[k][j]==2)
				a[i][j]=1;
}
int dfs(int k)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		if(a[k][i]&&!t[i])
		{
		t[i] = 1;
			if(!c[i]||dfs(c[i]))
			{
				c[i]=k;
				return 1;
			}
		}
	}
return 0;
}
int main()
{
	int i,j;
	int m;
	int e,s;
	while(scanf("%d%d",&n,&m))
	{
		if(n==0&&m==0)
			break;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				a[i][j]=0;
		memset(c,0,sizeof(c));
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&s,&e);
			a[s][e]=1;
		}
		floyd();
		ans = 0;
		for(i=1;i<=n;i++)
		{
			ans+=dfs(i);
			memset(t,0,sizeof(t));
		}
		printf("%d\n",n-ans);
	}
return 0;
}
