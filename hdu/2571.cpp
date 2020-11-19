#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int t,n,m;
int a[30][2020];
int f[30][2020];
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",a[i]+j);
		memset(f,0xc0,sizeof f);
		f[1][1]=a[1][1];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if(i<n)
					f[i+1][j]=max(f[i+1][j],f[i][j]+a[i+1][j]);
				if(j<m)
					f[i][j+1]=max(f[i][j+1],f[i][j]+a[i][j+1]);
				for(int k=2;k*j<=m;k++)
					f[i][j*k]=max(f[i][j*k],f[i][j]+a[i][j*k]);
			}
		printf("%d\n",f[n][m]);
	}
	return 0;
}
