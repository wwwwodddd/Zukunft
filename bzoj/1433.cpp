#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int n1,n2,n,csc,ans;
int v[105],l[105],a[105][105];
int h[2][105],e1[105],e2[105];
int g[105][105];
int dfs(int x)
{
	int i;
	for(i=0;i<n2;i++)
		if(g[x][i]&&!v[i])
		{
			v[i]=1;
			if(l[i]==-1||dfs(l[i]))
			{
				l[i]=x;
				return 1;
			}
		}
	return 0;
}
int main()
{
	int i,j;
	scanf("%d",&csc);
	while(csc--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&e1[i]);
		for(i=0;i<n;i++)
			scanf("%d",&e2[i]);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&a[i][j]);
		n1=n2=0;
		for(i=0;i<n;i++)
		{
			if(e1[i])
				h[0][n1++]=i;
			if(!e1[i]||!e2[i])
				h[1][n2++]=i;
		}
		for(i=0;i<n1;i++)
			for(j=0;j<n2;j++)
				g[i][j]=(a[h[0][i]][h[1][j]]||h[0][i]==h[1][j]);
		ans=0;
		memset(l,-1,sizeof(l));
		for(i=0;i<n1;i++)
		{
			memset(v,0,sizeof(v));
			if(dfs(i))
				ans++;
		}
		puts(ans==n2?"^_^":"T_T");
	}
	return 0;
}