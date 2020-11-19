#include<stdio.h>
#include<iostream>
using namespace std;
int a[100020];
int n,t,z;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		z=0xffffff;
		if(!n)
			z=0;
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		for(int i=n+1;i>0;i--)
			a[i]-=a[i-1];
		for(int j,i=j=1;i<=n+1;i++)
		{
			while(a[i]<0)
			{
				int t=min(a[j],-a[i]);
				a[i]+=t;
				a[j]-=t;
				z=min(z,i-j);
				if(!a[j])
					j++;
			}
		}
		printf("%d\n",z);
	}
	return 0;
}
