#include<stdio.h>
long long f[205][205];
int n,i,j,k;
int main()
{
	f[0][0]=1;
	for(i=1;i<=200;i++)
		for(j=i;j<=200;j++)
			f[i][j]=f[i-1][j-1]+f[i][j-i];
	while(scanf("%d %d",&n,&k),n+k)
		printf("%lld\n",f[k][n]);
	return 0;
}