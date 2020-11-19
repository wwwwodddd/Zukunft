#include<stdio.h>
int a[4][1000005],n,m;
int main()
{
	for(int i=0;i<=1000000;i++)
		a[0][i]=i+1,a[1][i]=i+2,a[2][i]=i+i+3;
	a[3][0]=5;
	for(int i=1;i<25;i++)
		a[3][i]=2*a[3][i-1]+3;
	while(~scanf("%d %d",&m,&n))
		printf("%d\n",a[m][n]);
	return 0;
}
