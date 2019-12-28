#include<iostream>
using namespace std;
int f[1010][1010];
int g[1010][1010];
int q[1000020][2];
int s,e;
int n,m;
int i,j,k;
int ans;
int xa,xb,ya,yb;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int tx,ty;
int F(int x,int y)
{
	if(f[x][y]==y)
		return y;
	return f[x][y]=F(x,f[x][y]);
}
void del(int x,int y)
{
	g[x][y]=1;
	f[x][y]=y+1;
}
void bfs(int x,int y)
{
	ans++;
	s=e=0;
	del(x,y);
	q[s][0]=x;
	q[s][1]=y;
	s++;
	while(s>e)
	{
		for(k=0;k<4;k++)
		{
			tx=q[e][0]+dx[k];
			ty=q[e][1]+dy[k];
			if(tx>=xa&&tx<=xb&&ty>=ya&&ty<=yb&&g[tx][ty]==0)
			{
				del(tx,ty);
				q[s][0]=tx;
				q[s][1]=ty;
				s++;
			}
		}
		e++;
	}
	return;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=n+1;j++)
			f[i][j]=j;
	while(m--)
	{
		ans=0;
		scanf("%d %d %d %d",&xa,&ya,&xb,&yb);
		for(i=xa;i<=xb;i++)
			for(j=ya;j<=yb;j=F(i,j))
				if(!g[i][j])
					bfs(i,j);
		printf("%d\n",ans);
	}
	return 0;
}