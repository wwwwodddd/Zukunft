#include<stdio.h>
long long a[10020];
int main()
{
int i;
a[0]=1;
for(i=1;i<10020;i++)
	{
	a[i]=a[i-1]*i;
	while(a[i]%10==0)
		a[i]/=10;
	a[i]%=1000000;
	}
while(scanf("%d",&i)!=EOF)
	printf("%5d -> %d\n",i,a[i]%10);
return 0;
}