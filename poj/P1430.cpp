#include<stdio.h>
int t,x,y;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&x,&y);
		printf("%d\n",((x-y)&((y-1)/2))?0:1);
	}
	return 0;
}