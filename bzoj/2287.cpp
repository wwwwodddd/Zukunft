#include<stdio.h>
#include<string.h>
int a[2020];
int f[2020];
int g[2020];
int n,m,i,j,k,p=10;
int main()
{
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	f[0]=1;
	for(i=0;i<n;i++)
		for(j=m;j>=a[i];j--)
			f[j]=(f[j]+f[j-a[i]])%10;
	for(i=0;i<n;i++)
	{
		memcpy(g,f,sizeof(f));
		for(j=a[i];j<=m;j++)
			g[j]=(g[j]+10-g[j-a[i]])%10;
		for(j=1;j<=m;j++)
			putchar('0'+g[j]);
		putchar('\n');
	}
	return 0;
}