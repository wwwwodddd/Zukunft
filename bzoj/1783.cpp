#include<stdio.h>
int a[700020];
int n,i;
long long x,y,z;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=n;i>0;i--)
		if(y+a[i]>=x)
		{
			z=x;
			x=y+a[i];
			y=z;
		}
	printf("%lld %lld",x,y);
	return 0;
}