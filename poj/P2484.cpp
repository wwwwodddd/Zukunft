#include<stdio.h>
int n;
int main()
{
	while(scanf("%d",&n)&&n)
		printf("%s\n",n<3?"Alice":"Bob");
	return 0;
}