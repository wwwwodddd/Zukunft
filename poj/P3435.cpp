#include<stdio.h>
#include<string.h>
int n,i,j,ans;
int g[105][105];
int v[105];
int CC(int x)
{
	int i,j;
	memset(v,0,sizeof(v));
	for(i=0;i<n*n;i++)
		v[g[i][x]]++;
	for(i=1;i<=n*n;i++)
		if(v[i]>=2)
			return 0;
	return 1;
}
int CR(int x)
{
	int i,j;
	memset(v,0,sizeof(v));
	for(i=0;i<n*n;i++)
		v[g[x][i]]++;
	for(i=1;i<=n*n;i++)
		if(v[i]>=2)
			return 0;
	return 1;
}
int CS(int x,int y)
{
	int i,j;
	memset(v,0,sizeof(v));
	for(i=x;i<x+n;i++)
		for(j=y;j<y+n;j++)
			v[g[i][j]]++;
	for(i=1;i<=n*n;i++)
		if(v[i]>=2)
			return 0;
	return 1;
}
int main()
{
	while(scanf("%d",&n)+1)
	{
		ans=1;
		for(i=0;i<n*n;i++)
			for(j=0;j<n*n;j++)
				scanf("%d",&g[i][j]);
		for(i=0;i<n*n;i++)
			ans&=CC(i);
		for(j=0;j<n*n;j++)
			ans&=CR(j);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				ans&=CS(i*n,j*n);
		if(ans)
			printf("CORRECT\n");
		else
			printf("INCORRECT\n");
	}
}