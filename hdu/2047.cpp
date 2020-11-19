#include<stdio.h>
long long f[50]={1,2};
int n;
int main()
{
	for(int i=2;i<45;i++)
		f[i]=f[i-1]+f[i-2]<<1;
	while(~scanf("%d",&n))
		printf("%I64d\n",f[n]+f[n-1]);
}
