#include<stdio.h>
int i,n;
int main()
{
	for(;~scanf("%d",&n);)
	{
		for(i=1;i<66;i++)
			if((18+n*i)%65==0)
				break;
		if(i<66)
			printf("%d\n",i);
		else
			puts("no");
	}
}
