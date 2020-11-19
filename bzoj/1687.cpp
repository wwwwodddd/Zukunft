#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
char a[120][120];
char g[120][120];
char c,k;
char s[4]={'N','W','S','E'};
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int p[120][120];
int m,n,sx,sy,ex,ey;
int i,j,z;
struct Node
{int x,y;}w,u;
queue<Node>q;
void dfs(int x,int y)
{
	if(p[x][y]==-1)
		return;
	dfs(x-dx[p[x][y]],y-dy[p[x][y]]);
	if(s[p[x][y]]==k)
		z++;
	else
	{
		if(k!=0)
			printf("%c %d\n",k,z/2);
		z=1;
		k=s[p[x][y]];
	}
}
int main()
{
	scanf("%d%d",&m,&n);
	for(i=1;i<2*m;i++)
		scanf("%s",a[i]+1);
	for(i=1;i<=2*m;i++)
		for(j=1;j<=2*n;j++)
		{
			g[i][j]=0;
			c=a[i][j];
			if(c=='-'||c=='|'||c=='+'||c=='S'||c=='E')
				g[i][j]=1;
			if(c=='S')
				sx=i,sy=j;
			if(c=='E')
				ex=i,ey=j;
		}
	w.x=sx;
	w.y=sy;
	q.push(w);
	p[sx][sy]=-1;
	while(!q.empty())
	{
		w=q.front();
		q.pop();
		if(w.x==ex&&w.y==ey)
			break;
		g[w.x][w.y]=0;
		for(i=0;i<4;i++)
		{
			u.x=w.x+dx[i];
			u.y=w.y+dy[i];
			if(g[u.x][u.y])
			{
				p[u.x][u.y]=i;
				q.push(u);
			}
		}
	}
	dfs(ex,ey);
	printf("%c %d\n",k,z/2);
	return 0;
}
