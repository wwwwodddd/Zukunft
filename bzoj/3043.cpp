#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
long long a[100020];
long long x,y;
int n;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%lld",a+i);
	for(int i=1;i<n;i++)
		x+=max(a[i]-a[i-1],0LL),y-=min(a[i]-a[i-1],0LL);
	printf("%lld\n%lld\n",max(x,y),abs(a[0]-a[n-1])+1LL);
	return 0;
}
