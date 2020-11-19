#include<stdio.h>
long long n,i;
int main()
{
	while(scanf("%I64d",&n),n)
	{
		for(i=111111111111111111ll;n%i;i/=10)
			;
		printf("%I64d\n",n/i);
	}
	return 0;
}
