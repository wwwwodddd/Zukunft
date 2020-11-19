#include<stdio.h>
#include<string.h>
int t,n,m,x;
int f[120][120];
void inc(int &x,int y)
{
	x=(x+y)%10000;
}
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d",&n,&m);
		memset(f,0,sizeof f);
		f[0][0]=1;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				scanf("%d",&x);
				for(int k=0;k<=x;k++)
					for(int l=0;k+l<=x;l++)
						if((l||k)&&i+k<n&&j+l<m)
							inc(f[i+k][j+l],f[i][j]);
			}
		printf("%d\n",f[n-1][m-1]);
	}
	return 0;
}
