#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int n,i,l,r;
int a[100020];
int b[100020];
int c[100020];
void add(int x,int y,int z)
{
	if(y<0||x>y)
		return;
	x=max(x,0);
	c[x]+=z;
	c[y+1]-=z;
}
int work(int *a,int *b)
{
	int z=0,re=0;
	memset(c,0,sizeof(c));
	for(i=0;i<n;i++)
	{
		l=lower_bound(b,b+n,a[i])-b;
		r=upper_bound(b,b+n,a[i])-b;
		add(i-l+1,i,2);
		add(i-r+1,i-l,1);
	}
	for(i=0;i<n;i++)
		z=max(z,re+=c[i]);
	return z;
}
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	for(i=0;i<n;i++)
		scanf("%d",b+i);
	sort(a,a+n);
	sort(b,b+n);
	printf("%d %d\n",work(a,b),n*2-work(b,a));
	return 0;
}