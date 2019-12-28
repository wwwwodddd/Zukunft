#include<stdio.h>
#include<string.h>
char s[1000];
int main()
{
	while(gets(s))
	{
		int i,j;
		for(i=0;s[i];i++)
		{
			if(s[i]==s[i+1])
			{
				for(j=i;s[i]==s[i+1]&&(i-j)<8;i++);
				printf("%d%c",i-j+1,s[i]);
			}
			else
			{
				printf("1");
				for(j=i;s[i]!=s[i+1]&&s[i];i++)
				{
					if('1'==s[i])
						printf("1");
					printf("%c",s[i]);
				}
				printf("1");
				if(s[i]==s[i+1])
					i--;
			}
		}
		memset(s,0,sizeof(s));
		printf("\n");
	}
	return 0;
}
