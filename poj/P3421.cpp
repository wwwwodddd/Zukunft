#include<stdio.h>
#include<string.h>
#include<math.h>
int a[20],c[20];
int n,i,j,k;
long long ans,p;
long long F(long long x)
{
	long long re=1;
	for(int i=1;i<=x;i++)
		re*=i;
	return re;
}
int sqrt(int n)
{
	return (int)sqrt((double)n);
}
int main()
{
	while(scanf("%d",&n)+1)
	{
		k=0;
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		for(i=2;i<=sqrt(n);i++)
		{
			if(n%i==0)
			{
				k++;
				a[k]=i;
				while(n%i==0)
				{
					c[k]++;
					n/=i;
				}
			}
		}
		if(n!=1)
		{
			k++;
			a[k]=n;
			c[k]++;
		}
		ans=0;
		for(i=1;i<=k;i++)
			ans+=c[i];
		p=F(ans);
		for(i=1;i<=k;i++)
			p/=F(c[i]);
		printf("%I64d %I64d\n",ans,p);
	}
	return 0;
}