#include<stdio.h>
int n;
int main()
{
	for(scanf("%*d");~scanf("%d",&n);)
		printf("%d\n",2*n*n-n+1);
}
