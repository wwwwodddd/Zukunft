#include<stdio.h>
#include<string.h>
int g[128][128],n,x,y,z;
int i,j,k;
int main()
{
	scanf("%d%d%d",&n,&x,&y);
	memset(g,0x3f,sizeof(g));
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		for(j=0;j<k;j++)
		{
			scanf("%d",&z);
			if(j)
				g[i][z]=1;
			else
				g[i][z]=0;
		}
	}
	for(k=1;k<=n;k++)
		for(j=1;j<=n;j++)
			for(i=1;i<=n;i++)
				if(g[i][j]>g[i][k]+g[k][j])
					g[i][j]=g[i][k]+g[k][j];
	printf("%d\n",g[x][y]==0x3f3f3f3f?-1:g[x][y]);
	return 0;
}
