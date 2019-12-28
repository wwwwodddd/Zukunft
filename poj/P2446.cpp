#include<stdio.h>
#include<string.h>
int n,m,z,ans;
int l[40][40][2];
int a[40][40];
int v[40][40];
int dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
int dfs(int x,int y)
{
	int i,xx,yy;
	for(i=0;i<4;i++)
	{
		xx=x+dx[i];
		yy=y+dy[i];
		if(a[xx][yy]&&!v[xx][yy])
		{
			v[xx][yy]=1;
			if(l[xx][yy][0]==0||dfs(l[xx][yy][0],l[xx][yy][1]))
			{
				l[xx][yy][0]=x;
				l[xx][yy][1]=y;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	int i,j,k;
	scanf("%d %d %d",&n,&m,&z);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			a[i][j]=((i^j)&1)+1;
	for(i=1;i<=z;i++)
	{
		scanf("%d %d",&k,&j);
		a[j][k]=0;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i][j]==1)
			{
				memset(v,0,sizeof(v));
				if(dfs(i,j))
					ans++;
			}
	printf("%s",n*m-2*ans-z?"NO":"YES");
	return 0;
}