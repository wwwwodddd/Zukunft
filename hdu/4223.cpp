#include<stdio.h>
#include<algorithm>
using namespace std;
int t,n,a[1020],z,k;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",a+i),a[i]+=a[i-1];
		sort(a,a+n+1);
		z=1<<30;
		for(int i=0;i<n;i++)
			z=min(z,a[i+1]-a[i]);
		printf("Case %d: %d\n",++k,z);
	}
	return 0;
}
