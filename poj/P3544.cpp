#include<stdio.h>
#include<iostream>
#include<algorithm>
#define x first
#define y second
using namespace std;
int n,z[1020];
long long v,t;
pair<long long,int>a[1020],b[1020];
int main()
{
	scanf("%d%I64d",&n,&t);
	for(int i=0;i<n;i++)
		scanf("%I64d",&a[i].x),a[i].y=i;
	for(int i=0;i<n;i++)
		scanf("%I64d",&b[i].x),b[i].x*=-t,b[i].y=i;
	for(int i=0;i<n;i++)
		scanf("%I64d",&v),b[i].x+=v;
	sort(a,a+n);
	sort(b,b+n);
	for(int i=0;i<n;i++)
		z[b[i].y]=a[i].y;
	for(int i=0;i<n;i++)
		printf("%d ",z[i]+1);
	return 0;
}
