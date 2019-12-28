#include<stdio.h>
long long k,n,m,t;
long long mod(long long a,long long b,long long c)
{
	if(b==1)
		return a%c;
	if(b==0)
		return 1;
	long long u=mod(a,b/2,c);
	long long re=u*u%c;
	if(b&1)
		re=re*a%c;
	return re;
}
int main()
{
	scanf("%I64d",&t);
	while(t--)
	{
		scanf("%I64d %I64d %I64d",&n,&k,&m);
		printf("%I64d\n",mod(mod(10,k,m)+1,n,m));
	}
	return 0;
}