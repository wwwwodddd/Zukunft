#include<stdio.h>
int n,i,j,k;
int main()
{
	while(scanf("%d",&n),n+1)
	{
		for(i=9;i>1;i--)
		{
			for(j=k=1;j<=i;j++)
				k*=i;
			if((n+i-1)%k==0)
				break;
		}
		if(i>1)
			printf("%d coconuts, %d people and 1 monkey\n",n,i);
		else
			printf("%d coconuts, no solution\n",n);
	}
	return 0;
}
