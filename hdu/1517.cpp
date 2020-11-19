#include<stdio.h>
long long x;
int p;
int main()
{
	for(;scanf("%I64d",&x);puts(p&1?"Stan wins.":"Ollie wins."))
		for(p=0;x-1;)
			x=(x-1)/(p++&1?2:9)+1;
}
