#include<stdio.h>
__int64 p;
int t=0;
int main()
{
	while(scanf("%I64d",&p)+1)
	{
		for(t=0;p!=1;)
			p=t++&1?(p+1)/2:(p+8)/9;
		puts(t&1?"Stan wins.":"Ollie wins.");
	}
	return 0;
}