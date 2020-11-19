#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
int a[12][12];
long long f[12][12][8333];
int n,m,q,t;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%d",&a[i][j]);
		memset(f,0,sizeof f);
		f[0][0][0]=1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				for(int k=0;k<2<<m;k++)
					if(f[i][j][k])
					{
						int x=(k>>j)&1;
						int y=(k>>j+1)&1;
						if(!a[i][j])
						{
							if(!x&&!y)
								f[i][j+1][k]+=f[i][j][k];
						}
						else
						{
							f[i][j+1][k^3<<j]+=f[i][j][k];
							if(x+y==1)
								f[i][j+1][k]+=f[i][j][k];
						}
					}
			for(int k=0;k<1<<m;k++)
				f[i+1][0][k<<1]=f[i][m][k];
		}
		printf("Case %d: There are %I64d ways to eat the trees.\n",++q,f[n][0][0]);
	}
	return 0;
}
