#include<stdio.h>
long long n,p=160729808;
int main()
{
	for(;scanf("%I64d",&n)+1;)
	{
		n%=p;
		printf("Triangle: %I64d\n",(n*(n+2)%p*(2*n+1))%p/8);
		printf("Diamond: %I64d\n",(n*(n+2)%p*(2*n-1))%p/8);
		printf("Parallelogram: %I64d\n",(n-1)*n%p*(n+1)%p*(n+2)%p/8);
	}
}
