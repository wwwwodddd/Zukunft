#include<stdio.h>
int t,n,m,s;
int a[120][120];
int b[120][120];
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",a[i]+j);
		s=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				b[i][j]=a[i][j]^a[i-1][j-1]^a[i][j-1]^a[i-1][j];
				if(b[i][j])
					s++;
			}
		puts(s&1?"Alice":"Bob");
	}
}
