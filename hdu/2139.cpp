#include<stdio.h>
long long n;
int main()
{
	while(scanf("%I64d",&n)+1)
		printf("%I64d\n",n*(n+1)*(n+2)/6);
}
