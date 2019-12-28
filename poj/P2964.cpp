#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
char s[105][105];
int a[105][105];
int f[205][105][105];
int i,j,k,m,n,t;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d",&m,&n);
		memset(s,0,sizeof s);
		memset(a,0,sizeof a);
		memset(f,0,sizeof f);
		for(i=1;i<=n;i++)
			scanf("%s",s[i]+1);
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				if(s[i][j]=='.')
					a[i][j]=0;
				else if(s[i][j]=='*')
					a[i][j]=1;
				else if(s[i][j]=='#')
					a[i][j]=2;
		f[2][1][1]=a[1][1];
		for(k=3;k<=m+n;k++)
			for(i=1;i<=n&&i<k;i++)
				if(a[i][k-i]!=2)
					for(j=1;j<=n&&j<k;j++)
						if(a[j][k-j]!=2)
				        {
							f[k][i][j]=max(f[k][i][j],f[k-1][i][j]);
							f[k][i][j]=max(f[k][i][j],f[k-1][i-1][j]);
							f[k][i][j]=max(f[k][i][j],f[k-1][i][j-1]);
							f[k][i][j]=max(f[k][i][j],f[k-1][i-1][j-1]);
							f[k][i][j]+=a[i][k-i];
							if(i!=j)
								f[k][i][j]+=a[j][k-j];
						}
		printf("%d\n",f[m+n][n][n]);
	}
	return 0;
}
