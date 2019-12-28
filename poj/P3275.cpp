#include<stdio.h>
int n,m,ans;
int u[1005][1005];
int d[1005][1005];
char g[1005][1005];
int main()
{
	int i,j,k;
	int a,b;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		u[a][++u[a][0]]=b;
		d[b][++d[b][0]]=a;
		g[a][b]=1;
	}
	for(k=1;k<=n;k++)
		for(i=1;i<=d[k][0];i++)
		{
			a=d[k][i];
			for(j=1;j<=u[k][0];j++)
			{
				b=u[k][j];
				if(!g[a][b])
				{
					u[a][++u[a][0]]=b;
					d[b][++d[b][0]]=a;
					g[a][b]=1;
				}
			}
		}
	for(i=1;i<=n;i++)
		ans+=d[i][0]+u[i][0];
	printf("%d\n",n*(n-1)/2-ans/2);
	return 0;
}