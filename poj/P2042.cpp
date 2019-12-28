#include<stdio.h>
int f[65536][5];
int i,j,k,n;
int main()
{
	f[0][0]=1;
	for(i=256;i>=0;i--)
		for(j=i*i;j<65536;j++)
			for(k=1;k<5;k++)
				f[j][k]+=f[j-i*i][k-1];
	while(scanf("%d",&n)&&n)
		printf("%d\n",f[n][4]);
	return 0;
}