#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int mo=9901;
int a[100020],b[100020];
int z,n,d,c[100020];
void R(int x,int y)
{
	for(x++;x<=n;x+=x&-x)
		c[x]+=y;
}
int G(int x)
{
	int _=0;
	for(x++;x;x-=x&-x)
		_+=c[x];
	return _;
}
int main()
{
	while(~scanf("%d %d",&n,&d))
	{
		memset(c,0,sizeof c);
		for(int i=z=0;i<n;i++)
			scanf("%d",a+i),b[i]=a[i];
		sort(b,b+n);
		for(int i=0;i<n;i++)
		{
			int p=lower_bound(b,b+n,a[i])-b;
			int u=upper_bound(b,b+n,a[i]+d)-b-1;
			int l=lower_bound(b,b+n,a[i]-d)-b-1;
			int q=(G(u)-G(l)+1)%mo;
			R(p,q);
			z+=q;
		}
		printf("%d\n",((z-n)%mo+mo)%mo);
	}
	return 0;
}
