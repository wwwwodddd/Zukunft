#include<stdio.h>
int g[305][305];
int c[101][305][305];
int n,m,q,o;
void R(int w,int x,int y,int z)
{
	int i,j;
	for(i=x;i<=n;i+=i&-i)
		for(j=y;j<=m;j+=j&-j)
			c[w][i][j]+=z;
}
int G(int w,int x,int y)
{
	int i,j,re=0;
	for(i=x;i;i-=i&-i)
		for(j=y;j;j-=j&-j)
			re+=c[w][i][j];
	return re;
}
int main()
{
	int i,j;
	int xa,ya,xb,yb,u;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			scanf("%d",&g[i][j]);
			R(g[i][j],i,j,1);
		}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&o);
		if(o==1)
		{
			scanf("%d %d %d",&xa,&ya,&u);
			R(g[xa][ya],xa,ya,-1);
			g[xa][ya]=u;
			R(g[xa][ya],xa,ya,1);
		}
		else
		{
			scanf("%d %d %d %d %d",&xa,&xb,&ya,&yb,&u);
			printf("%d\n",G(u,xb,yb)-G(u,xa-1,yb)-G(u,xb,ya-1)+G(u,xa-1,ya-1));
		}
	}
	return 0;
}