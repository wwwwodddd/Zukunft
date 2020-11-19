#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int a[1000005],i,n,p;
long long ans=0,sum=0;
void read(int&x) 
{
	char ch;
	while((ch=getchar())&&(ch<'0'||ch>'9'));
		x=ch-'0';
	while((ch=getchar())&&ch>='0'&&ch<='9')
		x=x*10+ch-'0';
}
int main()
{
	read(n);
	for(i=1;i<=n;i++) 
	{
		read(a[i]);
		sum+=a[i];
	}
	sum/=n;
	for(i=1;i<=n;i++) 
	{
		a[i]=a[i]-sum;
		a[i]=a[i]+a[i-1];
	}
	sort(a+1,a+n+1);
	p=a[n/2+1];
	for(i=1;i<=n;i++)
		ans+=abs(a[i]-p);
	printf("%lld\n",ans);
	return 0; 
}