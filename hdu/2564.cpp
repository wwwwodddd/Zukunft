/*
  Name: 
  Copyright: 
  Author: 
  Date: 29-12-11 23:53
  Description: 
*/
#include<stdio.h>
int n,i;
char s[10000];
int main()
{
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		gets(s+1);
		s[0]=' ';
		for(i=0;s[i];i++)
			if(s[i]>='a'&&s[i]<='z')
				s[i]=s[i]-'a'+'A';
		for(i=0;s[i];i++)
			if(s[i]==' '&&s[i+1]>='A'&&s[i+1]<='Z')
				printf("%c",s[i+1]);
		printf("\n");
	}
	return 0;
}
//gets qian yao chi diao \n
