#include<stdio.h>
int t,x,y;
char s[5];
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%s %d %d",s,&x,&y);
		if(*s=='+')
			printf("%d\n",x+y);
		else if(*s=='-')
			printf("%d\n",x-y);
		else if(*s=='*')
			printf("%d\n",x*y);
		else if(*s=='/')
		{
			if(x%y==0)
				printf("%d\n",x/y);
			else
				printf("%.2lf\n",(double)x/y);
		}
	}
	return 0;
}
