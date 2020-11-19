#include<stdio.h>
int a,b;
int gcd(int x,int y)
{
	return y?gcd(y,x%y):x;
}
int main()
{
	while(scanf("%d %d",&a,&b)+1)
		printf("%10d%10d    %s Choice\n\n",a,b,gcd(a,b)==1?"Good":"Bad");
}
