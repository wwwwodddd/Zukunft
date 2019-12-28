#include<stdio.h>
int main()
{
	int a,b,c,n;
	while(scanf("%d",&n)+1)
		if(n<2)
		{
			scanf("%d",&a);
			while(n--)
				scanf("%d",&a);
			printf("YES\n");
		}
		else if(n==2)
		{
			scanf("%d %d %d",&a,&b,&c);
			if(b*b>=4*a*c)
				printf("NO\n");
			else
				printf("YES\n");
		}
		else
		{
			scanf("%d",&a);
			while(n--)
				scanf("%d",&a);
			printf("NO\n");
		}
	return 0;
}
