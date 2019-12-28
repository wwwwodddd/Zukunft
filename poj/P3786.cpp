#include<stdio.h>
int f[120][120];
int g[120][120];
int t,x,y,z;
int main()
{
	g[0][0]=1;
	for(int i=1;i<=100;i++)
		for(int j=0;j<i;j++)
		{
			g[i][j]=g[i-1][j]+f[i-1][j];
			f[i][j]=g[i-1][j]+(j>0?f[i-1][j-1]:0);
		}
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d %d",&x,&y,&z);
		printf("%d %d\n",x,f[y][z]+g[y][z]);
	}
}
