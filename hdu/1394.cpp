#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int a[5020];
int c[5020];
int n,i;
int ans,z;
void R(int x,int y)
{
	for(;x<=n;x+=x&-x)
		c[x]+=y;
}
int G(int x)
{
	int re=0;
	for(;x;x-=x&-x)
		re+=c[x];
	return re;
}
int main()
{
	while(scanf("%d",&n)+1)
	{
		memset(c,0,sizeof(c));
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			a[i]++;
		}
		z=0;
		for(i=n;i>0;i--)
		{
			z+=G(a[i]);
			R(a[i],1);
		}
		ans=z;
		for(i=1;i<=n;i++)
		{
			z=z-a[i]+1+n-a[i];
			ans=min(ans,z);
		}
		printf("%d\n",ans);
	}
	return 0;
}