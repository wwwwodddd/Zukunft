#include<stdio.h>
int f[2020][2020];
int s[2020],t,n;
int main()
{
	f[0][0]=1;
	for(int i=1;i<=2000;i++)
	{
		for(int j=1;j<=2000;j++)
			s[i]+=f[i][j]=(f[i-1][j-1]+f[i-1][j]*j)%1000;
		s[i]%=1000;
	}
	for(scanf("%d",&t);t--;)
		scanf("%d",&n),printf("%d\n",s[n]);
	return 0;
}
