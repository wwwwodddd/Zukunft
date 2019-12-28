#include<iostream>
int g[20][20],m,n;
int a[20][20];
int w[20][20];
void del(int x,int y)
{
	a[x][y]=1;
	w[x][y]^=1;
	w[x+1][y]^=1;
	w[x][y+1]^=1;
	w[x-1][y]^=1;
	w[x][y-1]^=1;
}
int solve(int x)
{
	int i,j,k;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			w[i][j]=g[i][j];
	memset(a,0,sizeof(a));
	for(j=1;j<=n;j++)
		if((x>>(j-1))&1)
			del(1,j);
	for(i=2;i<=m;i++)
		for(j=1;j<=n;j++)
			if(w[i-1][j]==1)
				del(i,j);
	for(i=1;i<=n;i++)
		if(w[m][i]==1)
			return 0;
	return 1;
}
int main()
{
	int i,j,z=0;
	scanf("%d %d",&m,&n);
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&g[i][j]);
	for(i=0;i<(1<<n);i++)
		if(solve(i))
			break;
	if(i<(1<<n))
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
				printf("%d ",a[i][j]);
			printf("\n");
		}
	else
		printf("IMPOSSIBLE\n");
	return 0;
}