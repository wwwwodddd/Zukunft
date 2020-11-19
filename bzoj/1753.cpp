#include<stdio.h>
#include<algorithm>
using namespace std;
int n,i,a[10020];
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	printf("%d\n",a[n/2]);
	return 0;
}