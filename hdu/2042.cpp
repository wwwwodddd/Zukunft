#include<stdio.h>
int n;
int main()
{
	for(scanf("%*d");~scanf("%d",&n);)
		printf("%d\n",(1<<n)+2);
}
