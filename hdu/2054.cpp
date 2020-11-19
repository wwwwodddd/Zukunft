#include<stdio.h>
int a,b;
int main()
{
	while(~scanf("%d %d",&a,&b))
		puts(a-b?"NO":"YES");
}
