#include<stdio.h>
int csc;
long long x,z;
void work(long long x,long long z,int s,int e)
{
	int m=6-s-e;
	long long u=(1LL<<(x-1));
	if(z==u)
	{
		printf("%I64d %d %d\n",x,s,e);
		return;
	}
	if(z<u)
		work(x-1,z,s,m);
	else
		work(x-1,z-u,m,e);
}
int main()
{
	scanf("%d",&csc);
	while(csc--)
	{
		scanf("%I64d%I64d",&x,&z);
		work(x,z,1,3);
	}
	return 0;
}