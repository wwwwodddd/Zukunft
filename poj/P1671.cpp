#include<stdio.h>
double f[55][55];
double s[55];
int i,j,n;
int main()
{
	f[0][0]=1;
	for(i=1;i<=50;i++)
		for(j=1;j<=i;j++)
		{
			f[i][j]=j*f[i-1][j]+f[i-1][j-1];
			s[i]+=f[i][j];
		}
	while(scanf("%d",&n)&&n)
		printf("%d %.0f\n",n,s[n]);
	return 0;
}

