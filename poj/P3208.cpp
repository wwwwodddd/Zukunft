#include<stdio.h>
int g[20][20],f[20][20];
int t,n,m,p;
int main()
{
	for(int i=0;i<3;i++)
		g[i][6]=i+1;
	for(int i=0;i<10;i++)
		g[3][i]=3;
	f[0][3]=1;
	for(int i=1;i<=10;i++)
		for(int j=0;j<4;j++)
			for(int k=0;k<10;k++)
				f[i][j]+=f[i-1][g[j][k]];
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		for(m=1;m<11&&f[m][0]<n;m++)
			;
		p=0;
		for(int i=m,j;i;i--)
		{
			for(j=0;j<10;j++)
				if(n>f[i-1][g[p][j]])
					n-=f[i-1][g[p][j]];
				else
					break;
			printf("%d",j);
			p=g[p][j];
		}
		puts("");
	}
	return 0;
}
