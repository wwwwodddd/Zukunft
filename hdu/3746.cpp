#include<stdio.h>
#include<string.h>
char s[100020];
int p[100020];
int t,l,w;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%s",s+1);
		l=strlen(s+1);
		for(int i=2,j=0;i<=l;i++)
		{
			while(j&&s[i]!=s[j+1])
				j=p[j];
			if(s[i]==s[j+1])
				j++;
			p[i]=j;
		}
		w=l-p[l];
		printf("%d\n",w<l?w-(l-1)%w-1:l);
	}
}
