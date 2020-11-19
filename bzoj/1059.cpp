#include<stdio.h>
#include<string.h>
int g[256][256];
int l[256];
int v[256];
int csc,i,j,n;
int dfs(int x)
{
	int i;
	for(i=0;i<n;i++)
		if(g[x][i]&&!v[i])
		{
			v[i]=1;
			if(l[i]==-1||dfs(l[i]))
			{
				l[i]=x;
				return 1;
			}
		}
	return 0;
}
int main()
{
	scanf("%d",&csc);
	while(csc--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&g[i][j]);
		memset(l,-1,sizeof(l));
		for(i=0;i<n;i++)
		{
			memset(v,0,sizeof(v));
			if(!dfs(i))
				break;
		}
		puts(i==n?"Yes":"No");
	}
	return 0;
}