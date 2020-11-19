#include<stdio.h>
int t,n;
int main()
{
	for(scanf("%d",&t);t--;)
		scanf("%d",&n),printf("%d\n",(1<<n)-1);
}
