#include<stdio.h>
char g[8][8];
int n,ans;
void dfs(int x,int y,int m)
{
	int i,j;
	for(j=y;j>=0&&g[x][j]!='X';j--)
		if(g[x][j]=='y')
			return;
	for(j=x-1;j>=0&&g[j][y]!='X';j--)
		if(g[j][y]=='y')
			return;
	for(j=y+1;j<n&&g[x][j]!='X';j++)
		if(g[x][j]=='y')
			return;
	for(j=x+1;j<n&&g[j][y]!='X';j++)
		if(g[j][y]=='y')
			return;
	if(m>ans)
		ans=m;
	g[x][y]='y';
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(g[i][j]=='.')
				dfs(i,j,m+1);

	g[x][y]='.';
}
int main()
{
	int i,j;
	while(scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++)
			scanf("%s",g[i]);
		ans=0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(g[i][j]=='.')
					dfs(i,j,1);
		printf("%d\n",ans);
	}
	return 0;
}
