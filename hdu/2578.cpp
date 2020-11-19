#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int a[100020];
int main()
{
	int t,z,l,r,n,k;
	cin>>t;
	while(t--)
	{
		scanf("%d %d",&n,&k);
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		sort(a,a+n);
		n=unique(a,a+n)-a;
		z=l=0,r=n-1;
		while(l<n&&r>=0)
		{
			if(a[l]+a[r]>k)
				r--;
			else if(a[l]+a[r]<k)
				l++;
			else
				z++,r--,l++;
		}
		printf("%d\n",z);
	}
	return 0;
}
