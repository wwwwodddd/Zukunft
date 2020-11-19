#include<stdio.h>
#include<string.h>
char s[1020],c[1020];
int p[1020],n,m,z;
int main()
{
	while(scanf("%s %s",s+1,c+1),s[1]!='#')
	{
		m=strlen(s+1),n=strlen(c+1),z=0;
		for(int i=2,j=0;i<=n;i++)
		{
			while(j&&c[i]!=c[j+1])
				j=p[j];
			if(c[i]==c[j+1])
				j++;
			p[i]=j;
		}
		for(int i=1,j=0;i<=m;i++)
		{
			while(j&&s[i]!=c[j+1])
				j=p[j];
			if(s[i]==c[j+1])
				j++;
			if(j==n)
				z++,j=0;
		}
		printf("%d\n",z);
	}
	return 0;
}
