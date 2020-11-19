#include<stdio.h>
int n;
int main()
{
	while(~scanf("%d",&n))
		printf("%d\n",n*(n+2)*(2*n+1)/8);
	return 0;
}
