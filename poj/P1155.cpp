#include<iostream>
using namespace std;
int f[3010][3010],d[3010],w[3010];
int n,m,tot,t,x,y;
int h[3010],c[3010],p[3010],e[3010];
void add(int x,int y,int z)
{
	tot++;
	p[tot]=y;
	c[tot]=z;
	e[tot]=h[x];
	h[x]=tot;
}
void dfs(int u)
{
	f[u][0]=0;
	if(u>n-m)
	{
		d[u]=1;
		f[u][1]=w[u];
		return;
	}
	int t[3010],i,j,k,v;
	for(i=h[u];i!=0;i=e[i])
	{
		v=p[i];
		dfs(v);
		memcpy(t,f[u],sizeof(t));
		for(j=0;j<=d[u];j++)
			for(k=1;k<=d[v];k++)
				f[u][j+k]=max(f[u][j+k],f[v][k]+t[j]-c[i]);
		d[u]+=d[v];
	}
}
int main()
{
	int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n-m;i++)
	{
		scanf("%d",&t);
		while(t--)
		{
			scanf("%d%d",&x,&y);
			add(i,x,y);
		}
	}
	for(i=n-m+1;i<=n;i++)
		scanf("%d",w+i);
	memset(f,0xc0,sizeof(f));
	dfs(1);
	for(i=m;i>=0;i--)
		if(f[1][i]>=0)
		{
			printf("%d\n",i);
			break;
		}
	return 0;
}
