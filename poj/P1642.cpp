#include<stdio.h>
#include<string.h>
int g[25][25];
int n,i,j,k,u;
int F1(int x,int y)
{
	int i;
	for(i=0;;i++)
		if(g[x][i]<y)
			break;
	return i;
}
int F2(int x,int y)
{
	int i;
	for(i=0;;i++)
		if(g[i][x]<y)
			break;
	return i;
}
int main()
{
	while(scanf("%d",&n)&&n)
	{
		memset(g,0,sizeof(g));
		for(i=0;i<n;i++)
			for(j=0;;j++)
			{
				scanf("%d",&g[i][j]);
				if(!g[i][j])
					break;
			}
		j=0;
		for(i=1;j!=1;i++)
		{
			u=1;
			for(j=0;u;j++)
			{
				u=F1(j,i);
				if(u==0)
					printf("\n");
				else
					printf("%d ",u);
			}
		}
		j=0;
		for(i=0;j!=2;i++)
		{
			u=1;
			for(j=1;u;j++)
			{
				u=F2(i,j);
				if(u==0)
					printf("\n");
				else
					printf("%d ",u);
			}
		}
		printf("\n");
	}
	return 0;
}