#include<stdio.h>
int t,x,n,m,z,f[102][102][2];
int main()
{
	f[0][0][0]=1;
	for(int i=1;i<=100;i++)
	{
		f[i][0][0]=f[i-1][0][0]+f[i-1][0][1];
		f[i][0][1]=f[i-1][0][0];
		for(int j=1;j<=i;j++)
		{
			f[i][j][0]=f[i-1][j][0]+f[i-1][j][1];
			f[i][j][1]=f[i-1][j][0]+f[i-1][j-1][1];
		}
	}
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d %d",&x,&n,&m);
		printf("%d ",x);

		printf("%d\n",f[n][m][0]+f[n][m][1]);
	}
	return 0;
}
