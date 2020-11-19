#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int a[10020],t,mn,mx,n,c;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		int mn=*min_element(a,a+n);
		int mx=*max_element(a,a+n);
		if(mx-mn>1||n==1)
			puts("Impossible!");
		else
		{
			if(mn==mx)
			{
				if(mn==n-1)
					printf("%d\n",n);
				else if(mn==0)
					puts("0");
				else
					puts("Impossible!");
			}
			else
			{
				int c=count(a,a+n,mn);
				if(c==mx)
					printf("%d\n",c);
				else
					puts("Impossible!");
			}
		}
	}
	return 0;
}
