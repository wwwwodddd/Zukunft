#include<stdio.h>
#include<iostream>
using namespace std;
long long z;
int p[100020],h[100020],v=13331,n,m,x,y;
int F(int x,int y,int z)
{
	return h[y]-h[x]*p[z];
}
int lcp(int i,int j)
{
	int l=0,r=n-j+2;
	for(i--,j--;l<r-1;)
	{
		int m=l+r>>1;
		F(i,i+m,m)==F(j,j+m,m)?l=m:r=m;
	}
	return l;
}
int lcs(int i,int j)
{
	int l=0,r=i+1;
	for(;l<r-1;)
	{
		int m=l+r>>1;
		F(i-m,i,m)==F(j-m,j,m)?l=m:r=m;
	}
	return l;
}
int main()
{
	scanf("%d %d %d",&n,&m,&x),n--;
	for(int i=p[0]=1;i<=n;i++)
		p[i]=p[i-1]*v;
	for(int i=1;i<=n;i++)
		scanf("%d",&y),h[i]=h[i-1]*v+y-x,x=y;
	for(int l=1;l*2+m<=n;l++)
		for(int i=1;i+m+l<=n;i+=l)
			z+=max(min(lcp(i,i+m+l),l)+min(lcs(i,i+m+l),l)-l,0);
	printf("%lld",z);
	return 0;
}
