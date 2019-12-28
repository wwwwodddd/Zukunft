#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int g[25][25];
int t,n,x,y;
int main()
{
	while(~scanf("%d",&n))
	{
		memset(g,0x1f,sizeof g);
		for(int i=1;i<20;i++)
		{
			if(i>1)
				scanf("%d",&n);
			while(n--)
			{
				scanf("%d",&x);
				g[i][x]=g[x][i]=1;
			}
		}
		for(int k=1;k<=20;k++)
			for(int i=1;i<=20;i++)
				for(int j=1;j<=20;j++)
					g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
		scanf("%d",&n);
		printf("Test Set #%d\n",++t);
		while(n--)
		{
			scanf("%d %d",&x,&y);
			printf("%d to %d: %d\n",x,y,g[x][y]);
		}
		puts("");
	}
	return 0;
}
