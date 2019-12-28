#include<stdio.h>
int f[120];
int n,i,j;
int main()
{
	f[0]=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=0;j<n;j++)
			f[i]=(f[i]+f[j]*f[i-j-1])%9901;
	printf("%d",f[n]);
	return 0;
}