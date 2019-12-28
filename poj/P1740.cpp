#include<stdio.h>
#include<string.h>
int a[120],x,ans;
int main()
{
	int n;
	int i;
	while(scanf("%d",&n)&&n!=0)
	{
		ans=0;
		memset(a,0,sizeof(a));
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			a[x]++;
		}
		for(i=1;i<120;i++)
			ans|=a[i];
		printf("%d\n",ans&1);
	}
	return 0;
}