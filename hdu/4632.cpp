#include<stdio.h>
#include<string.h>
int f[1020][1020],t,p=10007,k,z;
char s[1020];
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%s",s);
		int n=strlen(s);
		z=0;
		for(int i=0;i<=n;i++)
			f[i][0]=f[0][i]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;i+j<=n;j++)
			{
				f[i][j]=p+f[i-1][j]+f[i][j-1]-f[i-1][j-1];
				if(s[i-1]==s[n-j])
					f[i][j]+=f[i-1][j-1];
				f[i][j]%=p;
			}
		for(int i=0;i<n;i++)
			z=(z+f[i][n-i-1])%p;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				if(s[i]==s[j])
					z=(z+f[i][n-j-1])%p;
		printf("Case %d: %d\n",++k,z);
	}
}
