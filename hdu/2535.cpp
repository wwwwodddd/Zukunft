#include<stdio.h>
#include<algorithm>
using namespace std;
int n,a[120],z;
int main()
{
	while(scanf("%d",&n),n)
	{
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		sort(a,a+n);
		for(int i=z=0;i<(n+2)/2;i++)
			z+=(a[i]+2)/2;
		printf("%d\n",z);
	}
	return 0;
}
