#include<stdio.h>
int n,k;
int main()
{
	while(~scanf("%d",&n))
	{
		if(n==1)
			puts("1");
		else if(n&2)
			puts("0");
		else
		{
			k=n>>2;
			for(int i=n;i>n-k;i--)
				printf("%d ",i);
			for(int i=n-k-1;i>2*k;i--)
				printf("%d ",i);
			printf("%d ",1);
			for(int i=2*k;i>k+1;i--)
				printf("%d ",i);
			printf("%d ",n-k);
			for(int i=k+1;i>1;i--)
				printf("%d ",i);
			puts("");
		}
	}
	return 0;
}
