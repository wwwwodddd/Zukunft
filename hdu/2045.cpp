#include<stdio.h>
long long f[60]={0,3,6,6};
int n;
int main()
{
	for(int i=4;i<55;i++)
		f[i]=f[i-1]+f[i-2]*2;
	while(~scanf("%d",&n))
		printf("%I64d\n",f[n]);
	return 0;
}
