#include<stdio.h>
#include<string.h>
char s[1000020];
int l;
int main()
{
	while(scanf("%s",s),*s!='E')
	{
		l=strlen(s);
		if(l==1&&*s=='1')
			puts("1");
		else if(l==1)
			puts("2");
		else if(l<10)
			puts("3");
		else
			puts("4");
	}
}
