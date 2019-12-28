#include<stdio.h>
#include<string.h>
int n,m,t,g[1020][1020];
int w,x,y,z,q;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		int i,j,v;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
			{
				scanf("%d",&v);
				g[i][j]=g[i-1][j]+g[i][j-1]-g[i-1][j-1]+v;
			}
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d%d%d%d",&w,&x,&y,&z);
			printf("Absolutni hodnota pohodlnosti je %d bodu.\n",g[y][z]-g[w-1][z]-g[y][x-1]+g[w-1][x-1]);
		}
		printf("\n");
	}
	return 0;
}