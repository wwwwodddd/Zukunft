#include<stdio.h>
#include<algorithm>
int a[1020];
int i,n,t,ans;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		std::sort(a,a+n+1);
        for(i=n;i>0;i-=2)
			ans^=a[i]-a[i-1]-1;
		if(ans)
			printf("%s","Georgia will win\n");
		else
			printf("%s","Bob will win\n");
	}
	return 0;
}
