#include<stdio.h>
int main()
{
int n,m,c;
while(scanf("%d %d %d",&n,&m,&c)&&n!=0&&m!=0)
	printf("%d\n",((m-7)*(n-7)+c)/2);
return 0;
}
