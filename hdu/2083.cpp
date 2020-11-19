#include<stdio.h>
#include<algorithm>
#include<numeric>
using namespace std;
int t,n,a[520];
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		nth_element(a,a+n/2,a+n);
		printf("%d\n",accumulate(a+n/2,a+n,0)-accumulate(a,a+n/2,0)-(n%2)*a[n/2]);
	}
}
