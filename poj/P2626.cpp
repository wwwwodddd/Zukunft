#include<iostream>
using namespace std;
int f[1020][16][16];
int a[1020][2];
int i,j,k,n=1;
int max(int x,int y,int z)
{
	x=x>y?x:y;
	x=x>z?x:z;
	return x;
}
int main()
{
	while(scanf("%d%d",&a[n][0],&a[n][1])+1)
		n++;
	for(i=1;i<n;i++)
	{
		for(j=0;j<=15;j++)
		{
			for(k=0;k<=15;k++)
			{
				if(j+k>i||j==0&&k==0)
					continue;
				if(j==0)
					f[i][j][k]=max(f[i-1][j][k-1]+a[i][1],f[i-1][j][k],0);
				else if(k==0)
					f[i][j][k]=max(f[i-1][j-1][k]+a[i][0],f[i-1][j][k],0);
				else
					f[i][j][k]=max(f[i-1][j][k],f[i-1][j-1][k]+a[i][0],f[i-1][j][k-1]+a[i][1]);
			}
		}
	}
	printf("%d\n",f[n-1][15][15]);
	return 0;
}