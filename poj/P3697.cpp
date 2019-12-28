#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
vector<int>a[10020];
queue<int>q;
int p[10020];
int v[10020];
int f[10020];
int x,y,z,n,m,k;
int F(int x)
{
	return f[x]!=x?f[x]=F(f[x]):x;
}
int main()
{
	for(;scanf("%d %d",&n,&m),n+m;)
	{
		z=0;
		memset(p,0,sizeof p);
		memset(v,0,sizeof v);
		for(int i=1;i<=n;i++)
			a[i].clear();
		for(int i=0;i<m;i++)
		{
			scanf("%d %d",&x,&y);
			a[x].push_back(y);
			a[y].push_back(x);
		}
		q.push(1);
		for(int i=1;i<=n+1;i++)
			f[i]=i;
		f[1]=2;
		v[1]=1;
		while(q.size())
		{
			int u=q.front();
			q.pop();
			fe(i,a[u])
				p[*i]=u;
			for(int i=F(1);i<=n;i=F(i+1))
				if(!v[i]&&p[i]!=u)
				{
					f[i]=i+1;
					v[i]=1;
					z++;
					q.push(i);
				}
		}
		printf("Case %d: %d\n",++k,z);
	}
	return 0;
}
