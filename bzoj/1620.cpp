#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
int t[1020],b[1020],a[1020];
int i,n,z=0x7fffffff;
bool cmp(const int x,const int y)
{
	return b[x]>b[y];
}
int main()
{
	scanf("%d", &n);
	for(i=0;i<n;i++)
		scanf("%d%d",&t[i],&b[i]),a[i]=i;
	sort(a,a+n,cmp);
	for(i=0;i<n;i++)
		z=min(z,b[a[i]])-t[a[i]];
	printf("%d\n",z>=0?z:-1);
	return 0;
}