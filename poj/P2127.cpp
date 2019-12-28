#include<stdio.h>
#include<string.h>
int f[520][520];
int g[520][520];
int a[520],b[520];
int i,j,k;
int n,m,ans;
int max(int x,int y)
{
	return x>y?x:y;
}
void print(int x,int y)
{
	if(!x||!y)
		return;
	if(g[x][y]==-1)
		print(x,y-1);
	else
	{
		print(g[x][y],y-1);
		printf("%d ",a[x]);
	}
}
int main()
{
	while(scanf("%d",&n)+1)
	{
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		scanf("%d",&m);
		for(i=1;i<=m;i++)
			scanf("%d",&b[i]);
		memset(g,0,sizeof(g));
		memset(f,0,sizeof(f));
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				if(a[i]!=b[j])
					f[i][j]=f[i][j-1],g[i][j]=-1;
				else
					for(k=0;k<i;k++)
						if((a[k]<a[i]&&f[i][j]<f[k][j-1]+1)||k==0)
							f[i][j]=f[k][j-1]+1,g[i][j]=k;
		ans=0;
		for(i=1;i<=n;i++)
			if(f[i][m]>f[ans][m])
				ans=i;
		printf("%d\n",f[ans][m]);
		print(ans,m);
		printf("\n");
	}
	return 0;
}