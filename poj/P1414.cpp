#include<stdio.h>
#include<string.h>
int g[20][20];
int q[20][20];
int dx[6]={-1,-1,0,0,1,1};
int dy[6]={-1,0,-1,1,0,1};
int n,m,ans;
int max(int x,int y)
{
	return x>y?x:y;
}
void dfs(int x,int y)
{
	if(q[x][y]!=-1)
		return;
	q[x][y]=g[x][y];
	for(int k=0;k<6;k++)
		if(g[x][y]==g[x+dx[k]][y+dy[k]])
			dfs(x+dx[k],y+dy[k]);
}
int calc(int x,int y)
{
	int i,j,k;
	memset(q,-1,sizeof(q));
	g[x][y]=m;
	for(i=1;i<=n;i++)
		for(j=1;j<=i;j++)
			if(g[i][j]==0)
				q[i][j]=0;
	int dec=0,inc=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=i;j++)
			if(q[i][j]==0)
				for(k=0;k<6;k++)
					dfs(i+dx[k],j+dy[k]);
/*	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
			printf("%d ",q[i][j]);
		printf("\n");
	}*/
	for(i=1;i<=n;i++)
		for(j=1;j<=i;j++)
			if(q[i][j]==-1)
				if(g[i][j]==m)
					dec++;
				else
					inc++;
	g[x][y]=0;
	return inc-dec;
}
int main()
{
	int i,j,k;
	while(scanf("%d %d",&n,&m)&&n+m)
	{
		for(i=1;i<=n;i++)
			for(j=1;j<=i;j++)
				scanf("%d",&g[i][j]);
		ans=-10000;
		for(i=1;i<=n;i++)
			for(j=1;j<=i;j++)
				if(g[i][j]==0)
					ans=max(ans,calc(i,j));
		printf("%d\n",ans);
	}
	return 0;
}