#include<stdio.h>
#include<string.h>
int n,m,k,l,t,ans,x,y,z;
char a[65][65][65];
char v[65][65][65];
int dx[6]={-1,0,0,1,0,0};
int dy[6]={0,-1,0,0,1,0};
int dz[6]={0,0,-1,0,0,1};
void dfs(int x, int y, int z)
{
	if(x>=0&&x<=n+1)
		if(y>=0&&y<=m+1)
			if(z>=0&&z<=k+1)
				if(!v[x][y][z]&&!a[x][y][z])
				{
					v[x][y][z]=1;
					for(int i=0;i<6;i++)
						dfs(x+dx[i],y+dy[i], z+dz[i]);
				}
}
int main()
{
	while(scanf("%d%d%d%d",&n,&m,&k,&l)&&n+m+k+l)
	{
		memset(a,0,sizeof(a));
		memset(v,0,sizeof(v));
		ans=0;
		for(int i=0;i<l;i++)
		{
			scanf("%d",&t);
			a[t%n+1][t/n%m+1][t/m/n+1]=1;
		}
		dfs(0,0,0);
		for(x=1;x<=n;x++)
			for(y=1;y<=m;y++)
				for(z=1;z<=k;z++)
					if(a[x][y][z])
						for(l=0;l<6;l++)
							if(v[x+dx[l]][y+dy[l]][z+dz[l]])
								ans++;
		printf("The number of faces needing shielding is %d.\n", ans);
	}
	return 0;
}