#include<iostream>
using namespace std;
int n,l[520],v[520],g[520][520];
int i,j,k,ans;
int dfs(int x)
{
	for(int i=1;i<=n;i++)
		if(!v[i]&&g[x][i])
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
	cin>>n>>k;
	while(k--)
	{
		scanf("%d%d",&i,&j);
		g[i][j]=1;
	}
	memset(l,-1,sizeof(l));
	for(i=1;i<=n;i++)
	{
		memset(v,0,sizeof(v));
		if(dfs(i))
		ans++;
	}
	printf("%d",ans);
	return 0;
}
