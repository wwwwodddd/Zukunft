#include<stdio.h>
int a[12],i,n;
int C(int x)
{
	for(i=10;i>=0;i--)
		if(x>=a[i])
			x-=a[i];
	return x;
}
int main()
{
	a[0]=1;
	for(i=1;i<11;i++)
		a[i]=a[i-1]*i;
	while(scanf("%d",&n)&&n>=0)
		printf("%s\n",C(n)||!n?"NO":"YES");
	return 0;
}