#include<stdio.h>
unsigned long long n,i,j,k,x,z=1,cnt,v;
int main()
{
	scanf("%llu",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%llu",&x);
		if(x==0)
			v=1;
		cnt+=x;
		for(j=1;j<x;j++)
			z=z*(++k)/j;
	}
	if(cnt!=(n-1)*2||v&&n!=1)
		puts("0");
	else
		printf("%llu",z);
	return 0;
}