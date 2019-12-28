#include<stdio.h>
#include<string.h>
int n,m,k,t,pp,i,j,l,ans;
int x[120],y[120],z[120];
int f[120][120],g[120][120],w[120][120];
int min(int a,int b)
{
	return a>b?b:a;
}
int abs(int x)
{
	return -min(x,-x);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&n,&m,&k);
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		memset(z,0,sizeof(z));
		for(i=1;i<=n;i++)
			scanf("%d",x+i);
		for(i=1;i<=m;i++)
			scanf("%d",y+i);
		for(i=k;i>=1;i--)
			scanf("%d",z+i);
		memset(f,30,sizeof(f));
		memset(g,30,sizeof(g));
		memset(w,30,sizeof(w));
		f[0][0]=0;
		for(i=1;i<=k;i++)
			for(j=1;j<=n;j++)
				f[i][j]=min(f[i-1][j-1],min(f[i-1][j],f[i][j-1]))+abs(z[i]-x[j]);
		g[n+1][0]=0;
		for(i=n;i>0;i--)
			for(j=1;j<=m;j++)
				g[i][j]=min(g[i+1][j-1],min(g[i+1][j],g[i][j-1]))+abs(x[i]-y[j]);
		w[k+1][m+1]=0;
		for(i=k;i>0;i--)
			for(j=m;j>0;j--)
				w[i][j]=min(w[i+1][j+1],min(w[i+1][j],w[i][j+1]))+abs(z[i]-y[j]);
		ans=0x3fffffff;
		for(i=0;i<=n;i++)
			for(j=0;j<=k;j++)
				for(l=0;l<=m;l++)
					ans=min(ans,min(f[j][i]+g[i][l]+w[j][l],min(f[j][i]+g[i][l]+w[j][l+1],min(f[j][i]+g[i][l]+w[j+1][l],min(f[j][i]+g[i][l]+w[j+1][l+1],min(f[j][i]+g[i+1][l]+w[j][l],min(f[j][i]+g[i+1][l]+w[j][l+1],min(f[j][i]+g[i+1][l]+w[j+1][l],f[j][i]+g[i+1][l]+w[j+1][l+1]))))))));
		printf("%d\n",ans);
	}
}
