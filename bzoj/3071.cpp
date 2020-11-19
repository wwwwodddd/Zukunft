#include<stdio.h>
int t,n;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		printf("%d\n",n*n-3*n+3);
	}
}
