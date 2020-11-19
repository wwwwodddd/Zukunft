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
vector<int>a[50020];
vector<int>b[50020];
vector<int>c[50020];
queue<int>q;
int f[50020][16];
int d[50020];
int h[50020];
int s[50020];
int n,x,y;
int lca(int x,int y)
{
	if(h[x]<h[y])
		swap(x,y);
	int k=h[x]-h[y];
	fr(i,16)
		if(k>>i&1)
			x=f[x][i];
	if(x==y)
		return x;
	for(int i=15;~i;i--)
		if(f[x][i]!=f[y][i])
			x=f[x][i],y=f[y][i];
	return f[x][0];
}
void dfs(int x)
{
	s[x]=1;
	fe(i,c[x])
		dfs(*i),s[x]+=s[*i];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		do
		{
			scanf("%d",&x);
			a[i].push_back(x);
			b[x].push_back(i);
			d[i]++;
		}
		while(x);
	}
	q.push(0);
	while(q.size())
	{
		x=q.front();
		q.pop();
		fe(i,b[x])
			if(!--d[*i])
				q.push(*i);
		if(!x)
			continue;
		y=*a[x].begin();
		fe(i,a[x])
			if(*i)
				y=lca(y,*i);
		c[y].push_back(x);
		h[x]=h[y]+1;
		f[x][0]=y;
		fo(i,15)
			f[x][i]=f[f[x][i-1]][i-1];
	}
	dfs(0);
	fo(i,n)
		printf("%d\n",s[i]-1);
}
