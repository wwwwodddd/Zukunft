#include<stdio.h>
int n,x;
long long sum,ans;
long long abs(long long x)
{
	return x>-x?x:-x;
}
int main()
{
	while(scanf("%d",&n)&&n)
	{
		ans=sum=0;
		while(n--)
			scanf("%d",&x),ans+=abs(sum+=x);
		printf("%I64d\n",ans);
	}
	return 0;
}
