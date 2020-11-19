#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int g[10020][2];
int l[10020];
int v[10020];
int a[10020];
int i,n,x,cnt;
int dfs(int x)
{
	int i;
	for(i=0;i<2;i++)
		if(!v[g[x][i]])
		{
			v[g[x][i]]=1;
			if(l[g[x][i]]==-1||dfs(l[g[x][i]]))
			{
				l[g[x][i]]=x;
				return 1;
			}
		}
	return 0;
}
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		g[i][0]=i-x;
		if(g[i][0]<0)
			g[i][0]+=n;
		g[i][1]=i+x;
		if(g[i][1]>=n)
			g[i][1]-=n;
		if(g[i][0]>g[i][1])
			swap(g[i][0],g[i][1]);
	}
	memset(l,-1,sizeof(l));
	for(i=n-1;i>=0;i--)
	{
		memset(v,0,sizeof(v));
		if(dfs(i))
			cnt++;
	}
	if(cnt!=n)
		puts("No Answer");
	else
	{
		for(i=0;i<n;i++)
			a[l[i]]=i;
		for(i=0;i<n;i++)
			printf("%d ",a[i]);
	}
	return 0;
}