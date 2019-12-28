#include<algorithm>
#include<iostream>
#include<stdio.h>
using namespace std;
int t,l,n,i,a[100020],b[200020],c[100020];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&l,&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
		{
			b[i]=min(a[i],l-a[i]);
			c[i]=max(a[i],l-a[i]);
		}
		sort(b,b+n);
		sort(c,c+n);
		printf("%d %d\n",b[n-1],c[n-1]);
	}
	return 0;
}