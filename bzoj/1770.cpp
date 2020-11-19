#include<stdio.h>
#include<bitset>
#include<iostream>
using namespace std;
int n,m,z;
bitset<40>a[40];
void dfs(int x,int y)
{
	if(y>=z)
		return;
	if(x==0)
	{
		z=min(z,y);
		return;
	}
	if(a[x][x])
	{
		for(int i=x+1;i<=n;i++)
			if(a[x][i])
				a[x][0]=a[x][0]^a[i][0];
		dfs(x-1,y+a[x][0]);
		for(int i=x+1;i<=n;i++)
			if(a[x][i])
				a[x][0]=a[x][0]^a[i][0];
	}
	else
	{
		dfs(x-1,y);
		a[x][0]=1;
		dfs(x-1,y+1);
		a[x][0]=0;
	}
}
int main()
{
	int x,y;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		a[x][y]=1;
		a[y][x]=1;
	}
	for(int i=1;i<=n;i++)
		a[i][0]=a[i][i]=1;
	for(int i=1;i<=n;i++)
	{
		int k=0;
		for(k=i;k<=n;k++)
			if(a[k][i])
				break;
		if(k<=n)
			swap(a[k],a[i]);
		for(k=i+1;k<=n;k++)
			if(a[k][i])
				a[k]^=a[i];
	}
	z=0x7fff;
	dfs(n,0);
	printf("%d",z);
	return 0;
}