#include<stdio.h>
long long f[40]={0,1},g[40]={0,1};
int main()
{
	for(int i=2;i<=31;i++)
		f[i]=g[i-1]*2+f[i-1],g[i]=g[i-1]*2+f[i-1]*2;
	for(int i=2;i<=31;i++)
		printf("N=%d: %I64d\n",i,(1LL<<2*i)-2*f[i]-2*g[i]-(1LL<<i)+2);
}
