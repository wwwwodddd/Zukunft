#include<stdio.h>
int f[120],g[120],a[120];
int i,n,p;
int main()
{
	while(scanf("%d %d",&n,&p)+1)
	{
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		f[1]=a[1];
		g[1]=a[1]*2-1;
		for(i=2;i<=n;i++)
		{
			f[i]=(f[i-1]*2+a[i])%p;
			g[i]=(f[i]+(a[i]+g[i-1])*(a[i]>1))%p;
		}
		printf("%d\n",g[n]%p);
	}
	return 0;
}