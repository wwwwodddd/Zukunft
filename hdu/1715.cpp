/*
  Name: 
  Copyright: 
  Author: 
  Date: 30-12-11 19:11
  Description: 
*/
#include<stdio.h>
int a[1020][1020];
int n,i,j,k,csc;
int main()
{
	a[1][0]=1;
	a[2][0]=1;
	for(i=3;i<=1000;i++)
	{
		for(j=0;j<1000;j++)
			a[i][j]=a[i-1][j]+a[i-2][j];
		for(j=0;j<1000;j++)
		{
			a[i][j+1]+=a[i][j]/100000000;
			a[i][j]%=100000000;
		}
	}
	scanf("%d",&csc);
	while(scanf("%d",&n)+1)
	{
		k=1000;
		while(a[n][k]==0)
			k--;
		printf("%d",a[n][k]);
		for(k--;k>=0;k--)
			printf("%08d",a[n][k]);
		puts("");
	}
	return 0;
}
//1A   yaofuxi gaojingdu muban le 
