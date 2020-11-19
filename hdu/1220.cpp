#include<stdio.h>
int main()
{
	int n;
	for(;~scanf("%d",&n);)
		printf("%d\n",((n*n*n-7)*n+6)*n*n/2);
}
