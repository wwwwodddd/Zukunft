#include<stdio.h>
int x,y,n,a,b;
int main()
{
	while(scanf("%d%d%d",&x,&y,&n)+1)
	{
		a=b=0;
		while(b!=n)
		{
			if(a==0)
			{
				a=x;
				printf("fill A\n");
			}
			if(b==y)
			{
				b=0;
				printf("empty B\n");
			}
			else
			{
				b+=a;
				a=0;
				if(b>y)
				{
					a=b-y;
					b=y;
				}
				printf("pour A B\n");
			}
		}
		printf("success\n");
	}
	return 0;
}