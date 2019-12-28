#include<iostream>
#define INF 0xffff
using namespace std;
int i,j,k,u,v,w;
int z[35];
int a[205][255],c[205];
int g[205][205];
int check(int x,int y)
{
	for(int i=1;i<=c[x];i++)
		for(int j=1;j<=c[y];j++)
			if(a[x][i]==a[y][j])
				if(a[x][i-1]==a[y][j+1]||a[x][i-1]==a[y][j-1]||a[x][i+1]==a[y][j+1]||a[x][i+1]==a[y][j-1])
					return 1;
	return 0;
}
void solve()
{
	int i,j,k,l,sum,ans,cnt;
	ans=INF;
	for(i=1;i<=u;i++)
	{
		sum=0;
		for(j=1;j<=w;j++)
		{
			cnt=INF;
			for(k=1;k<=u;k++)
				for(l=1;l<=c[k];l++)
					if(a[k][l]==z[j])
						if(g[k][i]<cnt)
						cnt=g[k][i];
			sum+=cnt;
		}
		if(ans>sum)
			ans=sum;
	}
	cout<<ans<<endl;
}
int main()
{
	while(scanf("%d %d",&u,&v)+1)
	{
		memset(a,0,sizeof(a));
		memset(z,0,sizeof(z));
		scanf("%d",&w);
		for(i=1;i<=w;i++)
			scanf("%d",&z[i]);
		for(i=1;i<=u;i++)
		{
			scanf("%d",&c[i]);
			for(j=1;j<=c[i];j++)
				scanf("%d",&a[i][j]);
			a[i][0]=a[i][c[i]];
			a[i][c[i]+1]=a[i][1];
		}
		for(i=0;i<=u;i++)
			for(j=0;j<=u;j++)
				g[i][j]=INF;
		for(i=1;i<=u;i++)
			g[i][i]=0;
		for(i=1;i<=u;i++)
			for(j=i+1;j<=u;j++)
				if(check(i,j))
					g[i][j]=g[j][i]=1;
		for(k=1;k<=u;k++)
			for(i=1;i<=u;i++)
				for(j=1;j<=u;j++)
					if(g[i][k]+g[k][j]<g[i][j])
						g[i][j]=g[i][k]+g[k][j];
		solve();
	}
	return 0;
}
