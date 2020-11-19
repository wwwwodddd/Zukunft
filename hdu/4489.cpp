#include<stdio.h>
#include<string.h>
typedef long long ll;
ll a[30],b[30];
int t,n;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		printf("%d ",n);
		scanf("%d",&n);
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		a[1]=1;
		for(int i=2;i<=n;i++)
		{
			memcpy(b,a,sizeof b);
			for(int j=1;j<=i;j++)
				a[j]=a[j-1]+b[i-j];
		}
		if(n==1)
			puts("1");
		else
			printf("%I64d\n",a[n]*2);
	}
	return 0;
}
