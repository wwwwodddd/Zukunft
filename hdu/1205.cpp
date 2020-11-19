#include<stdio.h>
#include<iostream>
using namespace std;
int t,n,x;
long long mx,sm;
long long c[1000020];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		sm=mx=0;
		while(n--)
		{
			scanf("%d",&x);
			sm+=x;
			mx=max(mx,(long long)x);
		}
		if(mx>sm-mx+1)
			puts("No");
		else
			puts("Yes");
	}
	return 0;
}
