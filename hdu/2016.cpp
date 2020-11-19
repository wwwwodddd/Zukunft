#include<stdio.h>
#include<algorithm>
using namespace std;
int n,a[120];
int main()
{
	for(;scanf("%d",&n),n;)
	{
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		swap(a[0],*min_element(a,a+n));
		for(int i=0;i<n;i++)
			printf("%d%c",a[i],i==n-1?'\n':' ');
	}
}
