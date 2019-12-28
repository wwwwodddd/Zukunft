#include<stdio.h>
#include<string.h>
int v[65536];
int a,b,c,s,and,or,i;
int main()
{
	while(scanf("%d",&a)&&a)
	{
		memset(v,0,sizeof(v));
		scanf("%d %d %d",&b,&c,&s);
		or=0;
		and=0xffffffff;
		do
		{
			v[s]=1;
			and&=s;
			or|=s;
			s=(a*s+b)%c;
		}
		while(v[s]==0);
		for(i=15;i>=0;i--)
			if((((and&or)>>i)&1)==1)
				putchar('1');
			else if((((and|or)>>i)&1)==0)
				putchar('0');
			else
				putchar('?');
		puts("");
	}
	return 0;
}