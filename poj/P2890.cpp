#include<iostream>
#include<vector>
using namespace std;
vector<int>v[1020];
int i,j,n,m,a,b,c;
int h[1020];
int ans;
void dfs(int u)
{
	for(int i=0;i<v[u].size();i++)
	{
		int z=v[u][i];
		if(!h[z])
		{
			h[z] = 1;
			dfs(z);
		}
	}
}
int main()
{
	while(scanf("%d%d",&n,&m)+1)
	{
		for(i=0;i<1000;i++)
			v[i].clear();
		while(m--)
		{
			scanf("%d%d", &a, &b);
			v[a].push_back(b);
		}
		ans=0;
		for(i=0;i<n;i++)
		{
			memset(h,0,sizeof(h));
			h[i]=1;
			dfs(i);
			for(j=0;j<n;j++)
				if(h[j])
					ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
