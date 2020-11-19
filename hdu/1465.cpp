#include<stdio.h>
int n;
long long f[22]={1};
int main()
{
	for(int i=2;i<=20;i++)
		f[i]=(i-1)*(f[i-1]+f[i-2]);
	while(~scanf("%d",&n))
		printf("%I64d\n",f[n]);
	return 0;
}
