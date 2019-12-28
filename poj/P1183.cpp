#include<stdio.h>
int a,i;
int main()
{
	scanf("%d",&a);
	for(i=a;(a*1LL*a+1)%i;i--);
	printf("%I64d",i+(a*1LL*a+1)/i+a+a);
	return 0;
}