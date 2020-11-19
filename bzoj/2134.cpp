#include<stdio.h>
#include<iostream>
using namespace std;
double ans;
int i,n,A,B,C,a[10000020];
int main()
{
	scanf("%d%d%d%d%d",&n,&A,&B,&C,a+1);
	for(i=2;i<=n;i++)
		a[i]=((long long)a[i-1]*A+B)%100000001;
	for(i=1;i<=n;i++)
		a[i]=a[i]%C+1;
	a[0]=a[n];
	for(i=1;i<=n;i++)
		ans+=1./max(a[i-1],a[i]);
	printf("%.3lf",ans);
	return 0;
}