#include<stdio.h>
int a,b,i,t;
int gcd(int x,int y)
{
	return y==0?x:gcd(y,x%y);
}
int main()
{
	while(scanf("%d %d",&a,&b)+1)
		printf("%10d%10d    %s Choice\n\n",a,b,gcd(a,b)==1?"Good":"Bad");
}
