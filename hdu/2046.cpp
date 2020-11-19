#include<stdio.h>
int n;
long long f[60]={1,1};
int main()
{
	for(int i=2;i<55;i++)
		f[i]=f[i-1]+f[i-2];
	while(~scanf("%d",&n))
		printf("%I64d\n",f[n]);
}
