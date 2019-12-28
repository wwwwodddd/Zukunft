#include<stdio.h>
int g[1020][1020];
int i,j,n;
int check()
{
	for(i=0;i<n-1;i++)
		for(j=1;j<n;j++)
			if(g[i][j-1]+g[i+1][j]!=g[i][j]+g[i+1][j-1])
				return 0;
	return 1;
}
int main()
{
	while(scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&g[i][j]);
		printf("%shomogeneous\n",check()?"":"not ");
	}
	return 0;
}