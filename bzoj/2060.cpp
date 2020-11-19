#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
vector<int>a[100020];
int f[100020];
int g[100020];
int n,x,y;
void dfs(int x,int y)
{
	for(vector<int>::iterator i=a[x].begin();i!=a[x].end();i++)
		if(*i!=y)
			dfs(*i,x),f[x]+=g[*i],g[x]+=f[*i];	
	g[x]=max(g[x]+1,f[x]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
		scanf("%d %d",&x,&y),a[x].push_back(y),a[y].push_back(x);
	dfs(1,0);
	printf("%d",g[1]);
	return 0;	
}
