#include<stdio.h>
#include<string.h>
char s[10020];
int t,k,f[10020],p=10007;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%s",s);
		int n=strlen(s);
		f[0]=1;
		for(int i=1;i<=n;i++)
		{
			f[i]=f[i-1];
			if(i>=4&&strncmp(s+i-4,"hehe",4)==0)
				f[i]+=f[i-4];
			f[i]%=p;
		}
		printf("Case %d: %d\n",++k,f[n]);
	}
	return 0;
}
