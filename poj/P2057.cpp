#include<iostream>
#include<algorithm>
using namespace std;
int w[1020],c[1020],f[1020],g[1020],h[1020],v[1020][1020],n;
bool cmp(int u,int v)
{
	return (g[u]+2)*h[v]<(g[v]+2)*h[u];
}
void dfs(int x)
{
	int i,j;
	f[x]=g[x]=h[x]=0;
	if(c[x]==0)
		h[x]=1;
	for(i=0;i<c[x];i++)
	{
		dfs(v[x][i]);
		h[x]+=h[v[x][i]];
	}
	sort(v[x],v[x]+c[x],cmp);
	for(i=0;i<c[x];i++)
	{
		f[x]+=(g[x]+1)*h[v[x][i]]+f[v[x][i]];
		g[x]+=g[v[x][i]]+2;
	}
	if(w[x])
		g[x]=0;
}
int main()
{
	int i,a;
	char o;
	while(scanf("%d",&n),n)
	{
		memset(c,0,sizeof(c));
		for(i=1;i<=n;i++)
		{
			scanf("%d %c",&a,&o);
			if(a!=-1)
				v[a][c[a]++]=i;
			w[i]=(o=='Y');
		}
		dfs(1);
		printf("%.4lf\n",1.*f[1]/h[1]);
	}
}