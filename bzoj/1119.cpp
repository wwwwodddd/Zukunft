#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int a[1000020],b[1000020],w[1000020];
long long ans,sum,cnt;
int i,j,z,n,mn,x,p;
char f[1000020];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&w[i]);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		a[x]=i;
	}
	for(i=1;i<=n;i++)
		scanf("%d",&b[i]);
	mn=0x3fffffff;
	for(i=1;i<=n;i++)
		mn=min(w[i],mn);
	ans=0;
	for(i=1;i<=n;i++)
		if(!f[i])
		{
			f[i]=1;
			z=w[i];
			sum=w[i];
			p=b[a[i]];
			cnt=1;
			while(!f[p])
			{
				cnt++;
				f[p]=1;
				sum+=w[p];
				z=min(z,w[p]);
				p=b[a[p]];
			}
			ans+=sum+min((cnt-2)*z,z+(cnt+1)*mn);
		}
	printf("%lld\n",ans);
}