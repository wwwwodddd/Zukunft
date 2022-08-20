#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
vector<int>a[10020];
vector<int>c[10020];
vector<int>b[10020];
vector<int>l[10020];
int v[10020];
int q[10020],bb,ff;
int st[10020],ss;
int dfn[10020],low[10020],cnt;
int r[10020],scc;
int vv[10020],rv[10020];
int p[10020];
int in[10020];
int n,m,s,t;
double e[105][105];
double w[10020];
void dfs1(int x)
{
	if(vv[x])
		return;
	vv[x]=1;
	fe(i,a[x])
		dfs1(*i);
}
void dfs2(int x)
{
	if(rv[x])
		return;
	rv[x]=1;
	fe(i,c[x])
		dfs2(*i);
}
void tarjan(int x)
{
	dfn[x]=low[x]=++cnt;
	v[x]=1;
	st[ss++]=x;
	fe(i,a[x])
	{
		if(!dfn[*i])
			tarjan(*i),low[x]=min(low[x],low[*i]);
		else if(v[*i])
			low[x]=min(low[x],dfn[*i]);
	}
	if(dfn[x]==low[x])
	{
		scc++;
		int u;
		do
		{
			u=st[--ss];
			v[u]=0;
			r[u]=scc;
			p[u]=l[scc].size();
			l[scc].push_back(u);
		}
		while(u!=x);	
	}
}
void work(int u)
{
//	cerr << "WORK: " << u << endl;
	int N=l[u].size();
	memset(e,0,sizeof e);
	for(int i=0;i<N;i++)
		e[i][N]=e[i][i]=-1;
	for(int i=0;i<N;i++)
	{
		int x=l[u][i];
		if(x==t)
		{
			e[i][N]=0;
			continue;	
		}
		fe(j,a[x])
		{
			if(r[*j]==u)
				e[i][p[*j]]+=1./a[x].size();
			else
			{
//				cerr << x <<a[x].size() << endl;
				e[i][N]-=w[*j]/a[x].size();
			}
		}
	}
//	cerr << "WORK: " << u << endl;
//	cerr << "end--" << endl;
	int t;
//	puts("EQU");
//	for(int i=0;i<N;i++)
//	{
//		for(int j=0;j<=N;j++)
//			printf("%.2lf ",e[i][j]);
//		puts("");
//	}
//	puts("END");
	for(int i=0;i<N;i++)
	{
//		puts("EQU");
//		for(int i=0;i<N;i++)
//		{
//			for(int j=0;j<=N;j++)
//				printf("%.2lf ",e[i][j]);
//			puts("");
//		}
//		puts("END");
		t=i;
		for(int j=i;j<N;j++)
			if(fabs(e[j][i])>fabs(e[t][i]))
				t=j;
		swap(e[i], e[t]);
		double u = e[i][i];
		for(int j = 0; j <= n; j++)
		{
			e[i][j] /= u;
		}
		for(int j=0;j<N;j++)
			if(j!=i)
			{
				double o=e[j][i];
				for(int k=0;k<=N;k++)
					e[j][k]-=o*e[i][k];
			}
	}
//	puts("EQU");
//	for(int i=0;i<N;i++)
//	{
//		for(int j=0;j<=N;j++)
//			printf("%.2lf ",e[i][j]);
//		puts("");
//	}
//	puts("END");
	for(int i=0;i<N;i++)
		w[l[u][i]]=e[i][N];
}
int main()
{
	scanf("%d %d %d %d",&n,&m,&s,&t);
	int x,y;
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&x,&y);
		a[x].push_back(y);
		c[y].push_back(x);
	}
	dfs1(s),dfs2(t);
//	for(int i=1;i<=n;i++)
//		cerr << vv[i] << ' ' << rv[i] << endl;
	for(int i=1;i<=n;i++)
		if(vv[i]&&!rv[i])
		{
			puts("INF");
			return 0;	
		}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=1;i<=n;i++)
		fe(j,a[i])
			if(r[i]!=r[*j])
				b[r[*j]].push_back(r[i]),in[r[i]]++;
//	for(int i=1;i<=n;i++)
//		cerr << r[i] << endl;
//	for(int i=1;i<=scc;i++)
//		cerr << in[i] << endl;
	for(int i=1;i<=scc;i++)
	{
		if(vv[l[i][0]])
		{
			work(i);
		}		
	}
//	for(int i=1;i<=n;i++)
//		cerr << w[i] << endl;
	printf("%.3lf\n",w[s]);
	return 0;
}
