#include<stdio.h>
char s[30],c;
int main()
{
	while(scanf("%s\n",s)+1)
	{
		while((c=getchar())+1&&c!='\n')
			if(c>='a'&&c<='z')
				printf("%c",s[c-'a']);
			else if(c>='A'&&c<='Z')
				printf("%c",s[c-'A']-'a'+'A');
			else
				printf("%c",c);
		puts("");
	}
	return 0;
}