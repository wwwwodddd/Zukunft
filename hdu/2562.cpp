/*
  Name: 
  Copyright: 
  Author: 
  Date: 29-12-11 23:48
  Description: 
*/
#include<stdio.h>
#include<string.h>
char s[5020];
int n,i;
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",s);
		for(i=0;s[i];i++)
			printf("%c",s[i^1]);
		printf("\n");
	}
	return 0;
}
//1A
