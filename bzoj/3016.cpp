#include<stdio.h>
char s[100020];
int z,d;
int main()
{
	scanf("%s",s);
	for(int i=0;s[i];i++)
	{
		if(s[i]=='(')
			d++;
		else
			d--;
		if(d<0)
			z++,d+=2; 
	}
	z+=d/2;
	printf("%d",z);
	return 0;
}
