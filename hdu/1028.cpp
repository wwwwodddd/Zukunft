#include<stdio.h>
int n;
long long f[122];
int main()
{
	f[0]=1;
	for(int i=1;i<121;i++)
		for(int j=i;j<121;j++)
			f[j]+=f[j-i];
	while(scanf("%d",&n)+1)
		printf("%I64d\n",f[n]);
	return 0;
}
