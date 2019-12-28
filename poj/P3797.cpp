#include<stdio.h>
int a[30],b[30],c[30],n,t,k;
int main()
{
	a[0]=a[1]=1;
	b[1]=1;
	c[1]=1;
	for(int i=2;i<=20;i++)
	{
		a[i]=a[i-1]+a[i-2]+2*b[i-1]+c[i-1];
		b[i]=a[i-1]+b[i-1];
		c[i]=a[i-1]+c[i-2];
	}
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		printf("%d %d\n",++k,a[n]);	
	}
}
