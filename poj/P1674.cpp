#include<stdio.h>
#include<algorithm>
using namespace std;
int t,i,n,a[10002];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		int ans=0;
		for(i=1;i<=n;i++)
			while(a[i]!=i)
				swap(a[i],a[a[i]]),ans++;
		printf("%d\n",ans);
	}
	return 0;
}