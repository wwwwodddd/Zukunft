#include<stdio.h>
char s[200020];
int f[200020];
int p[200020];
int t,n,z;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d%s",&n,s+1);
		for(int i=2,j=z=0;i<=n;i++)
		{
			while(j&&s[i]!=s[j+1])
				j=p[j];
			if(s[i]==s[j+1])
				j++;
			p[i]=j;
		}
		for(int i=1;i<=n;i++)
			z+=f[i]=f[p[i]]+1,z%=10007;
		printf("%d\n",z);
	}
}
