#include<stdio.h>
#include<string.h>
int n,x,y,w;
int m[120][120];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int dfs(int x,int y)
{
	if(m[x][y]==-1)
		return 0;
	int re=1,now;
	now=m[x][y];
	m[x][y]=-1;
	for(int i=0;i<4;i++)
		if(now==m[x+dx[i]][y+dy[i]])
			re+=dfs(x+dx[i],y+dy[i]);
	return re;
}
int main()
{
	while(scanf("%d",&n)&&n)
	{
		memset(m,-1,sizeof(m));
		w=0;
		for(int i=1;i<n;i++)
			for(int j=0;j<n;j++)
			{
				scanf("%d %d",&x,&y);
				m[x][y]=i;
			}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(m[i][j]>=0)
					if(dfs(i,j)!=n)
					{
						w=1;
						goto end;
					}
		end:
		printf("%s\n",w?"wrong":"good");
	}
	return 0;
}