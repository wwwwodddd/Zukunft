#include<stdio.h>
#include<iostream>
using namespace std;
int n,m,a[2020][2020],b[2020][2020],xa,xb,ya,yb;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",a[i]+j),a[i][j]+=a[i-1][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",b[i]+j),b[i][j]+=b[i][j-1];
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
		if(xa>xb)
			swap(xa,xb);
		if(ya>yb)
			swap(ya,yb);
		xa--,ya--;
		long long z=0;
		for(int j=1;j<=n;j++)
			z+=(long long)(a[xb][j]-a[xa][j])*(b[j][yb]-b[j][ya]);
		printf("%lld\n",z);
	}
	return 0;
}
