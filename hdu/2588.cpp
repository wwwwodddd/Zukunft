#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int f[100020];
int a[100020],c,z,t,n,m;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		c=z=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i*i<=n;i++)
			if(n%i==0)
			{
				a[c++]=i;
				if(i*i<n)
				a[c++]=n/i;
			}
		sort(a,a+c,greater<int>());
		for(int i=0;i<c&&a[i]>=m;i++)
		{
			f[i]=n/a[i];
			for(int j=0;j<i;j++)
				if(a[j]%a[i]==0)
					f[i]-=f[j];
			z+=f[i];
		}
		printf("%d\n",z);
	}
	return 0;
}
