#include<stdio.h>
double zp,p;
int n,m,r,c,zi,zj,zk,zl;
int a[300][300];
int main()
{
	while(scanf("%d %d %d %d",&n,&m,&r,&c),n)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",a[i]+j),a[i][j]+=a[i][j-1]+a[i-1][j]-a[i-1][j-1];
		zp=zi=zj=zk=zl=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				for(int k=i+r-1;k<=n;k++)
					for(int l=j+c-1;l<=m;l++)
					{
						p=(double)(a[k][l]-a[i-1][l]-a[k][j-1]+a[i-1][j-1])/((k-i+1)*(l-j+1));
						if(p>zp)
							zp=p,zi=i,zj=j,zk=k,zl=l;
					}
		printf("%d %d %d %d\n",zi,zj,zk,zl);
	}
	puts("*");
	return 0;
}
