#include<stdio.h>
int t,x;
int main()
{
	for(scanf("%d",&t);t--;)
		scanf("%*d %d",&x),puts(x&1?"0.00 1.00":"1.00 0.00");
}
