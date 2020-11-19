#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
#define X first
#define Y second
vector<pair<int,int> >a[10020];
int f[10020];
int g[10020];
int ans,n,x,y,z;
void dfs(int x,int y)
{
	fe(i,a[x])
		if(i->X!=y)
		{
			dfs(i->X,x);
			if(f[i->X]+i->Y<g[x])
			{
				if(f[i->X]+i->Y<f[x])
				{
					g[x]=f[x];
					f[x]=f[i->X]+i->Y;
				}
				else
					g[x]=f[i->X]+i->Y;
			}
		}
	ans=min(ans,f[x]+g[x]);
}
int main()
{
	for(;scanf("%d",&n),n;)
	{
		ans=0x3f3f3f3f;
		memset(f,0X3f,sizeof f);
		memset(g,0X3f,sizeof g);
		for(int i=1;i<n;i++)
		{
			scanf("%d %d %d",&x,&y,&z);
			a[x].push_back(make_pair(y,z));
			a[y].push_back(make_pair(x,z));
		}
		for(int i=1;i<=n;i++)
			if(a[i].size()==1)
				f[i]=0;
		dfs(1,0);
		for(int i=1;i<=n;i++)
			a[i].clear();
		printf("%d\n",ans);
	}
}
