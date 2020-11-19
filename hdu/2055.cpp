#include<stdio.h>
#include<iostream>
int t,x;
char s[5];
int F(char c)
{
	if(isupper(c))
		return c-'A'+1;
	else
		return 'a'-c-1;
}
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%s %d",&s,&x);
		printf("%d\n",x+F(*s));
	}
	return 0;
}
