#include<stdio.h>
#include<stdlib.h>
int n;
int main()
{
	while(~scanf("%d",&n))
		printf("%d\n",1<<__builtin_popcount(n));
	return 0;
}
