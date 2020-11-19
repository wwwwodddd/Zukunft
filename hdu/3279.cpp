#include<stdio.h>
#include<algorithm>
using namespace std;
int a[12],t,k;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&k);
		for(int i=0;i<10;i++)
			scanf("%d",a+i);
		sort(a,a+10);
		printf("%d %d\n",k,a[7]);
	}
	return 0;
}
