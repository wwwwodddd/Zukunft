#include<stdio.h>
#include<string.h>
int n,m,i,j,ans;
char c[1020][100];
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int max(int x,int y)
{
	return x>y?x:y;
}
int dfs(int x,int y)
{
	if(x<0||y<0||x>=m||y>=n)
		return 0;
	if(c[x][y]=='.')
		return 0;
	c[x][y]='.';
	int re=1;
	for(int i=0;i<4;i++)
		re+=dfs(x+dx[i],y+dy[i]);
	return re;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
		scanf("%s",c[i]);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			ans=max(ans,dfs(i,j));
	printf("%d",ans);
	return 0;
}