#include<stdio.h>
int t,x,y;
int main()
{
	for(scanf("%d",&t);t--;)
		scanf("%d %d",&x,&y),printf("%I64d\n",1LL<<x-y);
}
