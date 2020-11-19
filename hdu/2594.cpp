#include<stdio.h>
#include<string.h>
char s[100020];
int p[100020];
int n,m,l;
int main()
{
	while(~scanf("%s",s+1))
	{
		n=strlen(s+1);
		scanf("%s",s+1+n);
		l=strlen(s+1);
		m=l-n;
		for(int i=2,j=0;i<=l;i++)
		{
			while(j&&s[i]!=s[j+1])
				j=p[j];
			if(s[i]==s[j+1])
				j++;
			p[i]=j;
		}
		while(p[l]>n)
			l=p[l];
		while(p[l]>m)
			l=p[l];
		s[1+p[l]]=0;
		if(p[l])
			printf("%s %d\n",s+1,p[l]);
		else
			puts("0");
	}
	return 0;
}
