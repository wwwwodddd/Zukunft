#include<stdio.h>
#include<stdlib.h>
int n;
char s[1020];
void P(int x)
{
	if(!x)
		return;
	P(x/2);
	printf("%d",x&1);
}
int main()
{
	while(~scanf("%d",&n))
	{
		if(!n)
			puts("0");
		else
		{
			P(n);
			puts("");
		}
	}
}
