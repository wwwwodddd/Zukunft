#include<stdio.h>
#include<string.h>
double g[105][105];
double ans;
int c[105];
double a[105];
int n,m,t,i,j,k,x,y;
void mul(double a[][105],double b[][105])
{
	int i,j,k;
	double r[105][105];
	memset(r,0,sizeof(r));
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(g[i][j])
				for(k=1;k<=n;k++)
					r[i][k]+=a[i][j]*b[j][k];
	memcpy(a,r,sizeof(r));
	return ;
}
void s(int x)
{
	while(x)
	{
		mul(g,g);
		x>>=1;
	}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(g,0,sizeof(g));
		memset(c,0,sizeof(c));
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;i++)
			scanf("%lf",a+i);
		for(i=1;i<=m;i++)
		{
			scanf("%d %d",&x,&y);
			g[x][y]++;
			g[y][x]++;
			c[x]++;
			c[y]++;
		}
		for(i=1;i<=n;i++)
			if(c[i]==0)
				g[i][i]=1,c[i]++;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				g[i][j]/=c[i];
		s(m*m*4);
		for(i=1;i<=n;i++)
		{
			ans=0;
			for(j=1;j<=n;j++)
				ans+=a[j]*g[j][i];
			printf("%.3lf\n",ans);
		}
		printf("\n");
	}
	return 0;
}