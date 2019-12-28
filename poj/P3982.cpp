#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int a[100][25];
int main()
{
	int i,j,k=24;
	while(scanf("%d %d %d",&a[0][0],&a[1][0],&a[2][0])!=EOF)
	{
		k=24;
		for(i=3;i<100;i++)
		{
			for(j=0;j<25;j++)
				a[i][j]=a[i-1][j]+a[i-2][j]+a[i-3][j];
			for(j=0;j<25;j++)
			{
				a[i][j+1]+=a[i][j]/100000;
				a[i][j]%=100000;
			}
		}
		while(!a[99][k]&&k)
			k--;
		printf("%d",a[99][k]);
		for(k--;k>=0;k--)
			printf("%05d",a[99][k]);
		printf("\n");
		memset(a,0,sizeof(a));
	}
	return 0;
}