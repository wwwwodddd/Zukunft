#include<stdio.h>
int n;
long long f[50]={0,1};
int main()
{
	for(int i=2;i<=45;i++)
		f[i]=f[i-1]+f[i-2];
	scanf("%*d");
	while(~scanf("%d",&n))
		printf("%I64d\n",f[n]);
}
