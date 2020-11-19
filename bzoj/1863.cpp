#include<stdio.h>
#include<iostream>
using namespace std;
int i,j,n,l,r,a[1000020],f[1000020],g[1000020];
int check(int k)
{
	f[1]=g[1]=a[1];
	for(i=2;i<=n;i++)
	{
		g[i]=min(a[i],a[1]-f[i-1]);
		f[i]=max(0,a[1]+a[i]+a[i-1]-g[i-1]-k);
	}
	return f[n]==0;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<n;i++)
		l=max(l,a[i]+a[i+1]);
	r=l*2;
	while(l<r)
		if(check(l+r>>1))
			r=l+r>>1;
		else
			l=(l+r>>1)+1;
	printf("%d\n",l);
	return 0;
}