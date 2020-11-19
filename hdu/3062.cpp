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
vector<int>a[2020];
int dfn[2020],low[2020],cnt;
int s[2020],ss;
int v[2020],scc;
int r[2020];
void tarjan(int x)
{
	dfn[x]=low[x]=++cnt;
	s[ss++]=x;
	v[x]=1;
	fe(i,a[x])
		if(!dfn[*i])
			tarjan(*i),low[x]=min(low[x],low[*i]);
		else if(v[*i])
			low[x]=min(low[x],dfn[*i]);
	if(dfn[x]==low[x])
	{
		int u;
		scc++;
		do
		{
			u=s[--ss];
			v[u]=0;
			r[u]=scc;
		}
		while(u!=x);
	}
}
int main()
{
	int x1,y1,x2,y2,n,m;
	for(;scanf("%d %d",&n,&m)+1;)
	{
		fr(i,2*n)
			a[i].clear();
		memset(dfn,0,sizeof dfn);
		memset(low,0,sizeof low);
		memset(v,0,sizeof v);
		memset(s,0,sizeof s);
		memset(r,0,sizeof r);
		ss=scc=cnt=0;
		fr(i,m)
		{
			scanf("%d %d %d %d",&x1,&x2,&y1,&y2);
			a[2*x1+y1].push_back(2*x2+1-y2);
			a[2*x2+y2].push_back(2*x1+1-y1);
		}
		fr(i,2*n)
			if(!dfn[i])
				tarjan(i);
		fr(i,2*n)
			if(r[i]==r[i^1])
				goto XLk;
		puts("YES");
		continue;
		XLk:
		puts("NO");
	}
}
