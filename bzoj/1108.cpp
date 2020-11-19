#include<stdio.h>
long long ans;
int n,x,y,i;
int main()
{
	scanf("%d",&n);
	for(int i=0,x;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		ans+=y-x;
	}
	for(int i=0,x;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		ans+=x-y;
	}
	printf("%lld\n",ans);
}