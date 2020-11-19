#include<stdio.h>
#include<string.h>
#include<iostream>
#include<map>
#include<vector>
#include<string>
#define fr(i,n) for(int i=0;i<n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
using namespace std;
map<string,int>B,G;
vector<int>a[4020];
string s1,s2;
int n,m;
int dfn[4020];
int low[4020];
int s[4020],ss;
int v[4020];
int r[4020];
int c[4020];
int cnt,scc;
void tarjan(int x)
{
	dfn[x]=low[x]=++cnt;
	s[ss++]=x;
	v[x]=1;
	fe(i,a[x])
	{
		if(!dfn[*i])
			tarjan(*i),low[x]=min(low[x],low[*i]);
		else if(v[*i])
			low[x]=min(low[x],dfn[*i]);
	}
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
	cin>>n;
	fr(i,n)
	{
		cin>>s1>>s2;
		B[s1]=G[s2]=i;
	}
	cin>>m;
	fr(i,m)
	{
		cin>>s1>>s2;
		a[B[s1]].push_back(G[s2]);
	}
	fr(i,n)
		if(!dfn[i])
			tarjan(i);
	fr(i,n)
		c[r[i]]++;
	fr(i,n)
		if(c[r[i]]>1)
			puts("Unsafe");
		else
			puts("Safe");
	while(1);
	return 0;
}
