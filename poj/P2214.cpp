#include<stdio.h>
#include<algorithm>
int a[1000020],n,t,i,ans;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		std::sort(a,a+n);
		for(i=0;i<(n+1)/2;i++)
			ans+=a[i]/2;
		for(i=(n+1)/2;i<n;i++)
			ans+=a[i];
		printf("%d hlasu zajisti strane vitezstvi.\n",ans+1);
	}
	return 0;
}