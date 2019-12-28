#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
vector<int>a[5020],b[5020];
int f[5020];
int g[5020];
int ans;
int n,m,x,y;
int dfs(int z)
{
	if(f[z]!=0)
		return f[z];
	if(a[z].size()==0)
		return f[z]=1;
	for(int i=0;i<a[z].size();i++)
		f[z]+=dfs(a[z][i]);
	return f[z];
}
int dfs1(int z)
{
	if(g[z]!=0)
		return g[z];
	if(b[z].size()==0)
		return g[z]=1;
	for(int i=0;i<b[z].size();i++)
		g[z]+=dfs1(b[z][i]);
	return g[z];
}
int main()
{
	int i,j;
	while(scanf("%d%d",&n,&m)+1)
	{
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&x,&y);
			a[x].push_back(y);
			b[y].push_back(x);
			
		}
		for(i=1;i<=n;i++)
			if(a[i].empty())
				dfs1(i);
		for(i=1;i<=n;i++)
			if(b[i].empty())
				dfs(i);
		for(i=1;i<=n;i++)
			for(j=0;j<a[i].size();j++)
				ans=max(ans,g[i]*f[a[i][j]]);
		printf("%d\n",ans);
		for(i=1;i<=n;i++)
			a[i].clear(),b[i].clear();
	}
	return 0;
}
