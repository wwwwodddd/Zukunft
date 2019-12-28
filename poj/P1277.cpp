#include<stdio.h>
int t,n;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		if(n<3)
			puts("0");
		else if(n&1)
			printf("%d\n",n*(n-3)/2);
		else
			printf("%d\n",n*(n-4)/2+1);
	}
}