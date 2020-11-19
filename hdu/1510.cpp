#include<stdio.h>
#include<string.h>
int f[105][105][105];
int a[105][105];
char s[105][105]; 
int n,z;
int main()
{
	while(~scanf("%d",&n))
	{
		z=0;
		memset(f,0,sizeof f);
		for(int i=1;i<=n;i++)
			scanf("%s",s[i]+1);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				a[i][j]=a[i][j-1]+(s[i][j]=='.');
		for(int i=1;i<=n;i++)
			for(int j=0;j<n;j++)
				for(int k=j+1;k<=n;k++)
					if(a[i][k]-a[i][j]==k-j)
						z+=f[i][j][k]=f[i-1][j][k]+1;
		printf("%d\n",z);
	}
	return 0;
}
