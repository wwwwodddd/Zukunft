#include<stdio.h>
int lg(long long x)
{
	return x==1?0:lg(x/2)+1;
}
long long y;
int main()
{
	while(scanf("%*d %I64d",&y),y)
		printf("%d\n",lg(y&-y)+1);
}
