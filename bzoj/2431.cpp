#include<stdio.h>
#include<iostream>
using namespace std;
int f[1020][1020];
int s[1020][1020];
int n,m,i,j,k;
int main()
{
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++)
	{
		s[i][1]=f[i][1]=1;
		for(j=2;j<=k+1;j++)
		{
			f[i][j]=(s[i-1][j]-s[i-1][j-min(i,j)]+10000)%10000;
			s[i][j]=(s[i][j-1]+f[i][j])%10000;
		}
	}
	printf("%d",f[n][k+1]);
	return 0;
}