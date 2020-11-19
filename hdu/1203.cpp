#include<stdio.h>
#include<string.h>
char s[100001];
int c[26];
int main()
{
	for(;gets(s);)
	{
		memset(c,0,sizeof c);
		for(int i=0;s[i];i++)
			if(s[i]>='a'&&s[i]<='z')
				c[s[i]-'a']++;
		for(int i=0;i<26;i++)
			printf("%c:%d\n",i+'a',c[i]);
		puts("");
	}
	return 0; 
}
