#include<stdio.h>
#include<string.h>
#include<algorithm>
char s[60];
int i;
int main()
{
	while(scanf("%s",s)&&s[0]!='#')
	{
		for(i=0;i<strlen(s);i++)
			if(s[i]<s[i+1])
			{
				std::next_permutation(s,s+strlen(s));
				printf("%s\n",s);
				goto end;
			}
		printf("No Successor\n");
		end:;
	}
	return 0;
}