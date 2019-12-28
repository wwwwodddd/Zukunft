#include<stdio.h>
#include<string.h>
int g[1020][1020],d[1020];
int min(int a,int b)
{
	return a<b?a:b;
}
int main()
{
	int i,j,k=0;
	int n,m,t,f,x,y,z;
	scanf("%d",&t);
	while(t--)
	{
		memset(d,0,sizeof(d));
		memset(g,0,sizeof(g));
		scanf("%d %d",&n,&m);
		while(m--)
		{
			scanf("%d %d %d",&x,&y,&z);
			if(z>g[x][y])
				g[x][y]=z,g[y][x]=z;
		}
		d[1]=0x3fffffff;
		f=1;
		while(f)
		{
			f=0;
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
					if(d[i]<min(d[j],g[j][i]))
					{
						d[i]=min(d[j],g[j][i]);
						f=1;
					}
		}
		printf("Scenario #%d:\n%d\n\n",++k,d[n]);
	}
	return 0;
}