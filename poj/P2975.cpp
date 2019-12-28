#include<stdio.h>
int n,i,sum,ans;
int f[1020];
int main()
{
	while(scanf("%d",&n)&&n)
	{
		sum=ans=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&f[i]);
			sum^=f[i];
		}
		for(i=0;i<n;i++)
			if((sum^f[i])<f[i])
				ans++;
		printf("%d\n",ans);
	}
	return 0;
}