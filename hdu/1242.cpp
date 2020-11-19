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
int d[220][220];
int n,m;
char s[220][220];
int v[220][220];
queue<pair<int,int> >q;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int in(int x,int y)
{
	return x>0&&x<=n&&y>0&&y<=m&&s[x][y]!='#';
}
int main()
{
	for(;~scanf("%d %d",&n,&m);)
	{
		for(int i=1;i<=n;i++)
			scanf("%s",s[i]+1);
		memset(d,0x3f,sizeof d);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(s[i][j]=='a')
					d[i][j]=0,q.push(make_pair(i,j));
		while(q.size())
		{
			pair<int,int> u=q.front();
			q.pop();
			v[u.X][u.Y]=0;
			for(int k=0;k<4;k++)
			{
				int px=u.X+dx[k],py=u.Y+dy[k];
				if(!in(px,py))
					continue;
				if(d[px][py]>d[u.X][u.Y]+1+(s[px][py]=='x'))
				{
					d[px][py]=d[u.X][u.Y]+1+(s[px][py]=='x');
					if(!v[px][py])
						v[px][py]=1,q.push(make_pair(px,py));
				}
			}
		}
		int z=0xffffff;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(s[i][j]=='r')
					z=min(z,d[i][j]);
		if(z==0xffffff)
			puts("Poor ANGEL has to stay in the prison all his life.");
		else
			printf("%d\n",z);
	}
	return 0;
}