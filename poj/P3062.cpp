#include<stdio.h>
char c;
int main()
{
	while((c=getchar())+1)
		putchar(c);
	return 0;
}