#include<stdio.h>
char f[105][10020];
int n,m,t;
int main()
{
	for(int i=0;i<=100;i++)
	{
		f[i][0]=1;
		for(int j=1;j<i;j++)
			for(int k=0;k<=j*(j-1)/2;k++)
				f[i][k+j*(i-j)]|=f[j][k];
	}
	for(;scanf("%d %d",&n,&m),n+m;)
		printf(f[n][m]?"Case %d: %d lines with exactly %d crossings can cut the plane into %d pieces at most.\n":"Case %d: %d lines cannot make exactly %d crossings.\n",++t,n,m,n+m+1);
	return 0;
}
