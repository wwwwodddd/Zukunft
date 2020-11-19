#include<stdio.h>
#include<iostream>
using namespace std;
int a[1020],n,y;
long long f[1020],z;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=1;i<=n;i++)
		if(a[i])
			f[i]=1;
		else
			f[i]=0xffffffffffffffLL;
	for(int i=4;i<=n;i++)
		f[i]=min(f[i],f[i-1]+f[i-2]);
	for(int i=n-2;i;i--)
		f[i]=min(f[i],f[i+1]+f[i+2]);
	for(int i=4;i<=n;i++)
		f[i]=min(f[i],f[i-1]+f[i-2]);
	for(int i=2;i<=n;i+=2)
		if(f[i]==0xffffffffffffffLL)
			y++;
		else
			z+=f[i];
	cout<<y<<endl<<z<<endl;
	return 0;
}
