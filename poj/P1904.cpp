#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dfn[5020],low[5020];
vector<int>a[5020];
vector<int>b[5020];
int cnt,ss;
int s[5020];
int v[5020];
int r[5020];
int as[5020],ac;
int scc,n,m,i,j,k,x;
void tarjan(int x)
{
	int y,i,j;
	cnt++;
	dfn[x]=low[x]=cnt;
	v[x]=1;
	s[ss++]=x;
	for(i=0;i<b[x].size();i++)
	{
		if(dfn[b[x][i]]==0)
		{
			tarjan(b[x][i]);
			if(low[x]>low[b[x][i]])
				low[x]=low[b[x][i]];
		}
		else if(v[b[x][i]]==1&&low[x]>dfn[b[x][i]])
			low[x]=dfn[b[x][i]];
	}
	if(dfn[x]==low[x])
	{
		scc++;
		do
		{
			y=s[--ss];
			r[y]=scc;
			v[y]=0;
		}
		while(x!=y);
	}
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		while(k--)
		{
			scanf("%d",&x);
			b[i].push_back(x+n);
		}
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		b[x+n].push_back(i);
	}
	for(i=1;i<=2*n;i++)
		if(dfn[i]==0)
			tarjan(i);
	for(i=n+1;i<=2*n;i++)
		a[r[i]].push_back(i);
	for(i=1;i<=n;i++)
	{
		ac=j=k=0;
		sort(b[i].begin(),b[i].end());
		while(j<a[r[i]].size()&&k<b[i].size())
		{
			if(a[r[i]][j]==b[i][k])
			{
				as[ac++]=b[i][k];
				j++;
				k++;
			}
			else if(a[r[i]][j]>b[i][k])
				k++;
			else
				j++;
		}
		printf("%d ",ac);
		for(j=0;j<ac;j++)
			printf("%d ",as[j]-n);
		printf("\n");
	}
	return 0;
}