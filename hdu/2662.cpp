#include<stdio.h>
int t,i,j;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d",&i,&j);
		printf("%I64d\n",1LL*i*j-i-j);
	}
}
