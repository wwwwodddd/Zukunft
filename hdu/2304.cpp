#include<stdio.h>
int t,n,x,z;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		for(int i=z=1;i<=n;i++)
			scanf("%d",&x),z+=x-1;
		printf("%d\n",z);
	}
	return 0;
}
