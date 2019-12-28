#include<stdio.h>
char s;
int v;
int main()
{
	while((s=getchar())+1)
	{
		if(s=='"')
		{
			printf("%s",v?"''":"``");
			v^=1;
		}
		else
			printf("%c",s);
	}
	return 0;
}
