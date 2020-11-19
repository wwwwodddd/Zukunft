#include<stdio.h>
int n;
int main()
{
	while(~scanf("%d",&n))
	{
		for(int i=1;;i++)
			if(i*i>=n)
			{
				printf("%d\n",i*i==n);
				break;
			}
	}
	return 0;
}
