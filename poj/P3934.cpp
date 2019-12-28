#include<stdio.h>
int f[100][170];
int n,m,i,j;
int main()
{
	f[1][0]=1;
	for(i=2;i<=80;i++)
		for(j=i-1;j<=157;j++)
			if(j==1)
				f[i][j]=f[i-1][j-1]*2%9937;
			else
				f[i][j]=(f[i-1][j-2]*(i-2)+f[i-1][j-1]*2)%9937;
	while(scanf("%d %d",&n,&m)&&n+m)
		printf("%d\n",m>157?0:f[n][m]);
	return 0;
}