#include<iostream>
using namespace std;
int t,n,m,z,v[105],c[105];
int s[105],ss;
int g[105][105];
int dfs(int x)
{
	int i,j,k=0,re=0;
	v[x]=1;
	s[ss++]=x;
	for(i=1;i<=n;i++)
	{
		if(g[x][i]!=0)
		{
			g[x][i]--;
			g[i][x]--;
			k=0;
			if(v[i]==0)
				k=dfs(i)+1;
			else
			{
				z=s[--ss];
				while(z!=i)
				{
					c[z]=1;
					z=s[--ss];
				}
				ss++;
				return 1;
			}
			if(c[i])
				re^=k%2;
			else
				re^=k;
		}
	}
	return re;
}
int main()
{
	int i,j,x,y;
	int ans;
	while(scanf("%d",&t)+1)
	{
		ans=0;
		while(t--)
		{
			memset(v,0,sizeof(v));
			memset(g,0,sizeof(g));
			memset(c,0,sizeof(c));
			scanf("%d %d",&n,&m);
			ss=0;
			for(i=0;i<m;i++)
			{
				scanf("%d %d",&x,&y);
				g[x][y]++;
				g[y][x]++;
			}
			ans^=dfs(1);
		}
		if(ans)
			printf("Sally\n");
		else
			printf("Harry\n");
	}
	return 0;
}