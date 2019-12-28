#include<stdio.h>
int n,c;
int main()
{
	for(;~scanf("%d %d",&n,&c);)
		printf("%d\n",n?(c+n-1)/(2*n):0);
	return 0;
}
