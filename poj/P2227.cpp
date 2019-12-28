#include<iostream>
#include<algorithm>
#include<queue>
using namespace std ;
struct N
{
	int x,y,h ;
	bool operator<(const N &b)const
	{
		return b.h<h;
	};
	N(){};
	N(int x,int y,int h):x(x),y(y),h(h){};
};
priority_queue<N>q;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int i,j,n,m,x,y,z;
int g[400][400],v[400][400] ;
int in(int x,int y)
{
	return x<1||x>n||y<1||y>m;
}
int main ()
{
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&g[i][j]);
	N u;
	for(i=1;i<=n;i++)
	{
		q.push(N(i,1,g[i][1]));
		v[i][1]=1;
		q.push(N(i,m,g[i][m]));
		v[i][m]=1;
	}
	for (j=2;j<m;j++)
	{
		q.push(N(1,j,g[1][j]));
		v[1][j]=1;
		q.push(N(n,j,g[n][j]));
		v[n][j]=1;
	}
	while(!q.empty())
	{
		u=q.top();
		q.pop();
		for(i=0;i<4;i++)
		{
			x=u.x+dx[i];
			y=u.y+dy[i];
			if (!in(x,y)&&!v[x][y])
			{
				if(g[x][y]<u.h)
				{
					z+=u.h-g[x][y];
					q.push(N(x,y,u.h)) ;
				}
				else
					q.push(N(x,y,g[x][y]));
				v[x][y]=1;
			}
		}
	}
	printf("%d\n",z);
	return 0;
}