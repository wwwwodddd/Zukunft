#include<stdio.h>
int main()
{
	int t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		printf("%d\n",n*(n+1)*m*(m+1)/4);
	}
	return 0;
}
