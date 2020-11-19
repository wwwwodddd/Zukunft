#include<stdio.h>
#include<algorithm>
using namespace std;
int a[10020],i,n;
int main()
{
	while(scanf("%d",&n)+1)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		printf("%d\n",a[n/2]);
	}
	return 0;
}