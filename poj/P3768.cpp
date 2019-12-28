#include<iostream>
using namespace std;
int n,m,i,j,z;
char c[5][5],g[3010][3010];
void dfs(int k,int x,int y)
{
	int z=1,i,j;
	if(k==1)
	{
		for(i=x;i<x+n;i++)
			for(j=y;j<y+n;j++)
				g[i][j]=c[i-x][j-y];
		return;
	}
	for(i=0;i<k-2;i++)
		z*=n;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(c[i][j]!=' ')
				dfs(k-1,x+z*n*i,y+z*n*j);
}
int main()
{
	while(scanf("%d",&n),n)
	{
		getchar();
		memset(g,' ',sizeof(g));
		for(i=0;i<n;i++)
			gets(c[i]);
		scanf("%d",&m);
		dfs(m,0,0);
		z=1;
		for(i=0;i<m;i++)
			z*=n;
		for(i=0;i<z;i++)
		{
			g[i][z]=0;
			printf("%s\n",g[i]);
		}
	}
	return 0;
}