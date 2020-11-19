#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<queue>
#define X first
#define Y second
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
typedef pair<int,int> ii;
deque<ii>q;
char s[60][60];
int d[60][60];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int n,m,ans;
int in(int x,int y)
{
	return x>0&&y>0&&x<=n&&y<=m;
}
void bfs(int x,int y)
{
	q.push_back(ii(x,y));
	memset(d,0,sizeof d);
	d[x][y]=1;
	while(q.size())
	{
		ii u=q.front();
		q.pop_front();
		fr(k,4)
		{
			int nx=u.X+dx[k],ny=u.Y+dy[k];
			if(in(nx,ny)&&!d[nx][ny])
				if(s[nx][ny]==s[u.X][u.Y])
				{
					d[nx][ny]=d[u.X][u.Y];
					q.push_front(ii(nx,ny));
				}
				else
				{
					d[nx][ny]=d[u.X][u.Y]+1;
					q.push_back(ii(nx,ny));
				}
		}
	}
	int _=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			_=max(_,d[i][j]);
	if(s[x][y]=='B'&&_%2==1||s[x][y]=='W'&&_%2==0)
		_++;
	ans=min(ans,_-1);
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	ans=0xffff;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			bfs(i,j);
	printf("%d\n",ans);
	return 0;
}
