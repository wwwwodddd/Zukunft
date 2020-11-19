#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
vector<int>a[100020];
int s[100020],ss;
int dfn[100020];
int low[100020];
int r[100020];
int in[100020];
int ot[100020];
int c[100020];
int scc,cnt,n,m,x,y,k;
void dfs(int x)
{
	low[x]=dfn[x]=++cnt;
	s[ss++]=x;
	fe(i,a[x])
		if(!dfn[*i])
			dfs(*i),low[x]=min(low[x],low[*i]);
		else if(!r[*i])
			low[x]=min(low[x],dfn[*i]);
	if(low[x]==dfn[x])
	{
		scc++;
		int u; 
		do

		{
			u=s[--ss];
			r[u]=scc;
		}
		while(u!=x);
	}
}
int main()
{
	int t;
	for(scanf("%d",&t);t--;)
	{
		memset(dfn,0,sizeof dfn);
		memset(low,0,sizeof low);
		memset(r,0,sizeof r);
		memset(c,0,sizeof c);
		memset(in,0,sizeof in);
		memset(ot,0,sizeof ot);
		cnt=scc=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			a[i].clear();
		for(int i=0;i<m;i++)
			scanf("%d%d",&x,&y),a[x].push_back(y);
		for(int i=1;i<=n;i++)
			if(!dfn[i])
				dfs(i);
		if(scc==1)
		{
			printf("Case %d: %d\n",++k,-1);
			continue;
		}
		for(int i=1;i<=n;i++)
			fe(j,a[i])
				if(r[i]!=r[*j])
					ot[r[i]]++,in[r[*j]]++;
		for(int i=1;i<=n;i++)
			c[r[i]]++;
		int sz=n;
		for(int i=1;i<=scc;i++)
			if(!in[i]||!ot[i])
				sz=min(sz,c[i]);
		printf("Case %d: %I64d\n",++k,(long long)n*(n-1)-(long long)(n-sz)*sz-m);
	}
}
