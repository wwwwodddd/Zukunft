#include<stdio.h>
int a,i;
int main()
{
	scanf("%d",&a);
	for(i=1;a>>=1;i++);
	printf("%d",i);
}