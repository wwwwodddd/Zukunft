#include<stdio.h>
int main()
{
	int a,b,c;
	while(scanf("%d %d %d",&c,&b,&a)!=EOF)
	printf("%d %d %d\n",3*a-3*b+c,6*a-8*b+3*c,10*a-15*b+6*c);
	return 0;
}