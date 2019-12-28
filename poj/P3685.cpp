#include<stdio.h>
#include<iostream>
using namespace std;
int t,n;
long long m;
long long B(long long b,long long c)//count <=0
{
	int re=0;
	for(long long i=1<<16;i;i>>=1)
		if(re+i<=n)
			if((re+i)*(re+i)+b*(re+i)+c<=0)
				re+=i;
	return re;
}
long long check(long long x)//count <=x
{
	long long re=0;
	for(long long j=1;j<=n;j++)
		re+=B(100000+j,(j-100000)*j-x);
	return re;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %I64d",&n,&m);
		long long l=-1000000000000LL;
		long long r=-l;
		while(l<r-1)
		{
			if(check(l+r>>1)<m)
				l=(l+r>>1);
			else
				r=(l+r>>1);
		}
		printf("%I64d\n",r);
	}
	return 0;
}
