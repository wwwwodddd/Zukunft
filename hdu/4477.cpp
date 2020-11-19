#include<stdio.h>
int f[50010][2],p=1000000,t,n;
int z[50010];
int main()
{
	f[0][0]=1;
	for(int j=1;j<320;j++)
	{
		for(int i=0;i<50010;i++)
			f[i][j&1]=0;
		for(int i=j;i<50010;i++)
		{
			f[i][j&1]=(f[i-j][j&1]+f[i-j][j-1&1])%p;
			z[i]=(z[i]+f[i][j&1])%p;
		}
	}
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		printf("%d\n",(z[n]+p-1)%p);
	}
}
