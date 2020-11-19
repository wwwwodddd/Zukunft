#include<stdio.h>
long long x,y;
int main()
{
	while(~scanf("%I64X%I64X",&x,&y))
		if(x+y>=0)
			printf("%I64X\n",x+y);
		else
			printf("-%I64X\n",-x-y);
}
