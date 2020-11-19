#include<stdio.h>
int t,n,a,b;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d %d",&n,&a,&b);
		for(;n--;)
			a*=b-n;
		printf("%d\n",a);
	}
}
