#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
vector<int>a[220];
int low[220],dfn[220],r[220],s[220],v[220];
int t,n,m,cnt,ss,scc,x,y;
void tarjan(int x)
{
	low[x]=dfn[x]=++cnt;
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
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d",&n,&m);
		for(int i=0;i<2*n;i++)
			a[i].clear();
		while(m--)
		{
			char c[2][2];
			scanf("%1s%d%1s%d",c[0],&x,c[1],&y);
			x=x*2-2+(*c[0]=='h');
			y=y*2-2+(*c[1]=='h');
			a[x].push_back(y^1);
			a[y].push_back(x^1);
		}
		memset(dfn,0,sizeof dfn);
		memset(low,0,sizeof low);
		for(int i=0;i<2*n;i++)
			if(!dfn[i])
				tarjan(i);
		for(int i=0;i<n;i++)
			if(r[i*2]==r[i*2+1])
			{
				puts("BAD");
				goto end;
			}
		puts("GOOD");
		end:;
	}
	return 0;
}
