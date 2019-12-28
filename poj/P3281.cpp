#include<iostream>
#include<queue>
#include<string.h>
#include<stdio.h>
using namespace std;
int d[500],f[500][500],p[500];
int g[500][500];
int n,m,l;
queue<int>q;
int S(int s,int t)
{
	int re=0,u,v;
	while(1)
	{
		memset(d,0,sizeof(d));
		d[s]=0xffffff;
		q.push(s);
		while(!q.empty())
		{
			u=q.front();
			q.pop();
			for(v=s;v<=t;v++)
				if(!d[v]&&g[u][v]>f[u][v])
				{
					q.push(v);
					d[v]=min(d[u],g[u][v]-f[u][v]);
					p[v]=u;
				}
		}
		if(d[t]==0)
			return re;
		re+=d[t];
		for(u=t;u!=s;u=p[u])
		{
			f[p[u]][u]+=d[t];
			f[u][p[u]]-=d[t];
		}
	}
}
int main()
{
	int x,y,z,ans,i;
	scanf("%d%d%d",&n,&m,&l);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		g[i][i+n]=1;
		while(x--)
		{
			scanf("%d",&z);
			g[2*n+z][i]=1;
		}
		while(y--)
		{
			scanf("%d",&z);
			g[i+n][2*n+m+z]=1;
		}
	}
	for(i=2*n+1;i<=2*n+m;i++)
		g[0][i]=1;
	for(i=2*n+m+1;i<=2*n+m+l;i++)
		g[i][2*n+m+l+1]=1;
	printf("%d\n",S(0,2*n+m+l+1));
	return 0;
}
