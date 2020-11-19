#include<stdio.h>
int f[1020][2020][2];
int t,n,k,p=100000007;
void inc(int&x,int y)
{
	x=(x+y)%p;	
}
int main()
{
	f[1][1][0]=f[1][2][1]=1;
	for(int i=1;i<1000;i++)
		for(int j=0;j<=2*i;j++)
		{
			inc(f[i+1][j+2][1],f[i][j][0]);
			inc(f[i+1][j+2][1],f[i][j][1]);
			inc(f[i+1][j+1][0],f[i][j][0]);
			inc(f[i+1][j+1][0],f[i][j][1]);
			inc(f[i+1][j+1][1],f[i][j][1]);
			inc(f[i+1][j+1][1],f[i][j][1]);
			inc(f[i+1][j+1][1],f[i][j][0]);
			inc(f[i+1][j+1][1],f[i][j][0]);
			inc(f[i+1][j][0],f[i][j][1]);
			inc(f[i+1][j][0],f[i][j][1]);
			inc(f[i+1][j][0],f[i][j][0]);
			inc(f[i+1][j][1],f[i][j][1]);
		}
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d",&n,&k);
		printf("%d\n",(f[n][k][0]+f[n][k][1])%p);
	}
	return 0;
}
