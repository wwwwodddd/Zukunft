#include<stdio.h>
#include<algorithm>
using namespace std;
int a[20020];
int n,m,i,x;
int main()
{
	while(scanf("%d %d",&n,&m)+1)
	{
		n+=m;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		n=unique(a,a+n)-a;
		for(i=0;i<n-1;i++)
			printf("%d ",a[i]);
		printf("%d",a[i]);
		puts("");
	}
	return 0;
}