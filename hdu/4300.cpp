#include<stdio.h>
#include<string.h>
char c[30],w[30];
char s[100020];
int p[100020];
int t;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%s",c);
		for(int i=0;i<26;i++)
			w[c[i]-'a']='a'+i;
		scanf("%s",s+1);
		int l=strlen(s+1);
		for(int i=2,j=0;s[i];i++)
		{
			while(j&&c[s[i]-'a']!=s[j+1])
				j=p[j];
			if(c[s[i]-'a']==s[j+1])
				j++;
			p[i]=j;
		}
		int j=l;
		for(;2*j>l;j=p[j])
			;
		printf("%s",s+1);
		for(int i=j+1;i<=l-j;i++)
			printf("%c",w[s[i]-'a']);
		puts("");
	}
	return 0;
}
