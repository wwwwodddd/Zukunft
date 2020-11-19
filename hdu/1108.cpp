#include<stdio.h>
int n,m;
int gcd(int x,int y)
{
	if(y==0)
		return x;
	return gcd(y,x%y);
}
int main()
{
	while(scanf("%d %d",&n,&m)+1)
		printf("%d\n",n*m/gcd(n,m));	
	return 0;
}
