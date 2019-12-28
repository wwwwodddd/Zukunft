#include<stdio.h>
int i,j,p[800],g[800][800],v[800],x[800],y[800],n,m;
int d[800];
int dis(int i,int j)
{
	return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}
void prim()
{
	int mn,u;
	for(i=2;i<=n;i++)
		d[i]=g[1][i],p[i]=1;
	v[1]=1;
	for(i=1;i<n;i++)
	{
		mn=0xffffff;
		u=-1;
		for(j=1;j<=n;j++)
			if(d[j]<mn&&!v[j])
				mn=d[u=j];
		v[u]=1;
		for(j=1;j<=n;j++)
			if(g[u][j]<d[j]&&!v[j])
			{
				d[j]=g[u][j];
				p[j]=u;
			}
	}
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d",x+i,y+i);
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
			g[i][j]=g[j][i]=dis(i,j);
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",x,y);
		g[*x][*y]=g[*y][*x]=0;
	}
	prim();
	for(i=2;i<=n;i++)
		if(g[i][p[i]])
			printf("%d %d\n",i,p[i]);
	return 0;
}