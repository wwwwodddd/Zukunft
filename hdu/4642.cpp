#include<stdio.h>
int t,n,m;
int a[120][120];
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%d",a[i]+j);
		puts(a[n-1][m-1]?"Alice":"Bob");
	}
}
