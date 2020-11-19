#include<stdio.h>
#include<iostream>
#include<string.h>
#include<queue>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> ii;
int n,m,sx,sy,ex,ey;
int d[520][520];
char s[520][520];
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
deque<ii>q;
int main()
{
	while(scanf("%d %d",&n,&m),n+m)
	{
		for(int i=0;i<n;i++)
			scanf("%s",s[i]);
		scanf("%d %d %d %d",&sx,&sy,&ex,&ey);
		q.push_back(ii(sx,sy));
		memset(d,0,sizeof d);
		d[sx][sy]=1;
		while(q.size())
		{
			ii u=q.front();
			q.pop_front();
			for(int k=0;k<4;k++)
			{
				int px=u.X+dx[k],py=u.Y+dy[k];
				if(px<0||py<0||px>=n||py>=m)
					continue;
				if(d[px][py])
					continue;
				if(s[u.X][u.Y]==s[px][py])
					q.push_front(ii(px,py)),d[px][py]=d[u.X][u.Y];
				else if(s[u.X][u.Y]!=s[px][py])
					q.push_back(ii(px,py)),d[px][py]=d[u.X][u.Y]+1;
			}
		}
		printf("%d\n",d[ex][ey]-1);
	}
	return 0;
}
