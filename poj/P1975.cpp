#include<stdio.h>
#include<string.h>
int g[120][120];
int n,m,ans,t;
int i,j,k,x,y,a,b;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(g,0,sizeof(g));
		scanf("%d %d",&n,&m);
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&x,&y);
			g[x][y]=1;
		}
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				for(k=1;k<=n;k++)
					if(g[j][i]&&g[i][k])
						g[j][k]=1;
		ans=0;
		for(i=1;i<=n;i++)
		{
			a=b=0;
			for(j=1;j<=n;j++)
				if(g[j][i])
					a++;
			for(j=1;j<=n;j++)
				if(g[i][j])
					b++;
			if(a>(n-1)/2||b>(n-1)/2)
				ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}