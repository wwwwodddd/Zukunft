#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int c[100020];
int s[100020];
int i,n;
long long ans,sum;
int a[100020][2];
int l0[100020],c0;
int l1[100020],c1;
int cmp(const void *a,const void *b)
{
	return *(int*)b-*(int*)a;
}
void R(int x,int y,int z[])
{
	for(;x<=n;x+=x&-x)
		z[x]+=y;
}
long long G(int x,int z[])
{
	long long _=0;
	for(;x;x-=x&-x)
		_+=z[x];
	return _;
}
int main()
{
	while(~scanf("%d",&n))
	{
		memset(c,0,sizeof c);
		memset(s,0,sizeof s);
		memset(a,0,sizeof a);
		c0=c1=0;
		ans=sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a[i][1],&a[i][0]);
			l0[c0++]=a[i][0];
			l1[c1++]=a[i][1];
		}
		sort(l0,l0+c0);
		sort(l1,l1+c1);
		for(i=0;i<n;i++)
		{
			a[i][0]=lower_bound(l0,l0+c0,a[i][0])-l0+1;
			a[i][1]=lower_bound(l1,l1+c1,a[i][1])-l1+1;
		}
		qsort(a,n,8,cmp);
		for(i=0;i<n;i++)
		{
			ans+=(a[i][1]*(2*G(a[i][1],c)-i)-2*G(a[i][1],s)+sum)*a[i][0];
			sum+=a[i][1];
			R(a[i][1],1,c);
			R(a[i][1],a[i][1],s);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}