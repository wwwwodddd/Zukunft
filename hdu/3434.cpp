#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
int a[1000020],k,n,t;
long long x,y;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		for(int i=x=y=0;i<n;i++)
			scanf("%d",a+i);
		for(int i=1;i<n;i++)
			x+=max(a[i]-a[i-1],0),y-=min(a[i]-a[i-1],0);
		printf("Case %d: %I64d %d\n",++k,max(x,y),abs(a[0]-a[n-1])+1);
	}
	return 0;
}
