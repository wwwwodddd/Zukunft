#include<stdio.h>
#include<string.h>
int g[305][305];
int n,m,t,i,j,k,x,y,z;
int max(int x,int y)
{
	return x>y?x:y;
}
int main()
{
	scanf("%d %d %d",&n,&m,&t);
	memset(g,0x3f,sizeof(g));
	while(m--)
	{
		scanf("%d %d %d",&x,&y,&z);
		g[x][y]=z;
	}
	for(k=1;k<=n;k++)
		for(j=1;j<=n;j++)
			for(i=1;i<=n;i++)
				if(g[i][j]>max(g[i][k],g[k][j]))
					g[i][j]=max(g[i][k],g[k][j]);
	while(t--)
	{
		scanf("%d %d",&x,&y);
		printf("%d\n",g[x][y]==0x3f3f3f3f?-1:g[x][y]);
	}
	return 0;
}