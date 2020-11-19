/*
  Name: 
  Copyright: 
  Author: 
  Date: 30-12-11 19:03
  Description: 
*/
#include<stdio.h>
int f[2020][2020];
int n,m,i,j,csc;
int main()
{
	f[0][0]=1;
	for(i=1;i<=2010;i++)// yuan 2000
		for(j=1;j<=i;j++)
			f[i][j]=(f[i-1][j-1]+f[i-1][j])%1007;
	scanf("%d",&csc);
	while(scanf("%d %d",&m,&n)+1)
		printf("%d\n",f[n+1][m+1]);
	return 0;
}
//zhuyibianjie duokaidian buaishi
