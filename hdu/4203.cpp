#include<stdio.h>
int t,n,k;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d",&n,&k);
		if(k&1)
			printf("%d\n",n&1);
		else
		{
			if(n%(k+1)==k)
				printf("%d\n",k);
			else
				printf("%d\n",n%(k+1)%2);
		}
	}
	return 0;
}
