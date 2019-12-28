#include<stdio.h>
#include<string.h>
int n,l=0,r=2147483647;
int main()
{
	int x;
	char str[10];
	while(scanf("%d",&n)&&n)
	{
		getchar();
		l=0;
		r=2147483647;
		while(gets(str)&&strcmp(str,"right on"))
		{
			if(strcmp(str,"too high")==0&&n<r)
				r=n;
			else if(strcmp(str,"too low")==0&&n>l)
				l=n;
			scanf("%d",&n);
			getchar();
		}
		if(n>l&&n<r)
			printf("Stan may be honest\n");
		else
			printf("Stan is dishonest\n");
	}
	return 0;
}