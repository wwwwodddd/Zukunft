#include<stdio.h>
int a[3020],n,o;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n*(n-1)/2;i++)
		scanf("%d",a+i);
	o=a[0]+a[1]-a[n-1]>>1;
	printf("%d\n",o);
	for(int i=0;i<n-1;i++)
		printf("%d\n",a[i]-o);
	return 0;
}
