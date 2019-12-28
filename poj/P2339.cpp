#include<iostream>
using namespace std;
int n,m,l,x,y,g[105][105];
int a[105][105];
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
char s[120];
int main()
{
	int t,i,j,k;
	scanf("%d",&t);
	while(t--)
	{
	scanf("%d%d%d", &n, &m, &l);
	for(i=1;i<=n;i ++)
	{
		scanf("%s",s+1);
		for(j=1;j<=m;j++)
			if(s[j]=='R')
				g[i][j]=1;
			else if(s[j]=='S')
				g[i][j]=3;
			else
				g[i][j]=5;
	}
	while(l--)
	{
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				for(k=0;k<4;k++)
				{
					x=i+dx[k];
					y=j+dy[k];
					if((g[x][y]+2)%6==g[i][j])
					{
						a[i][j]=1;
						break;
					}
				}
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				if(a[i][j])
				{
					g[i][j]=(g[i][j]+4)%6;
					a[i][j]=0;
				}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(g[i][j]==1)
					printf("R");
				else if(g[i][j]==3)
					printf("S");
				else
					printf("P");
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}