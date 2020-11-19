#include<stdio.h>
int g[202][202];
int n,m,i,j,k,x,y,ans;
int main()
{
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&x,&y);
		g[x][y]=g[y][x]=1;
	}
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			if(g[i][j]==0)
				for(k=j+1;k<=n;k++)
					if(g[i][k]==0&&g[j][k]==0)
						ans++;
	printf("%d",ans);
	return 0;
}