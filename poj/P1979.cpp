#include<stdio.h>
#include<string.h>
char a[30][30];
int ans;
int m,n;
int bfs(int x,int y)
{
if(a[x][y]=='#')
	return 0;
if(!(x>=0&&x<m&&y>=0&&y<n))
	return 0;
a[x][y]='#';
return 1+bfs(x-1,y)+bfs(x+1,y)+bfs(x,y-1)+bfs(x,y+1);
}
int main()
{
int i,j,t=1,c=0;
while(scanf("%d %d",&n,&m)&&n!=0&&m!=0)
{
memset(a,0,sizeof(a));
for(i=0;i<m;i++)
	scanf("%s",a[i]);
for(i=0;i<m;i++)
	for(j=0;j<n;j++)
		if(a[i][j]=='@')
			ans=bfs(i,j);
			goto end;
end:
printf("%d\n",ans);
}
return 0;
}