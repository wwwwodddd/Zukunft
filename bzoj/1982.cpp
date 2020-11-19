#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int i,n,a[100020];
int main()
{
	while(scanf("%d",&n)+1)
	{
		for(i=0;i<n;i++)
			scanf("%d",a+i);
		if(n&1)
			a[n++]=0;
		sort(a,a+n);
		for(i=0;i<n;i+=2)
			if(a[i]!=a[i+1])
				break;
		puts(i==n?"second player":"first player");
	}
	return 0;
}