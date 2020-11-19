#include<stdio.h>
#include<algorithm>
using namespace std;
long long a[5][222];
long long s1[40020],s2[40020];
int c1,c2;
int t,n;
int ok(long long x)
{
	int l=0,r=c2-1;
	while(l<c1&&r>=0)
		if(s1[l]+s2[r]==x)
			return 1;
		else if(s1[l]+s2[r]<x)
			l++;
		else
			r--;
	return 0;
}
int main()
{
	for(scanf("%d",&t);t--;)
	{
		c1=c2=0;
		scanf("%d",&n);
		for(int i=0;i<5;i++)
			for(int j=0;j<n;j++)
				scanf("%I64d",a[i]+j);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				s1[c1++]=a[0][i]+a[1][j];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				s2[c2++]=a[2][i]+a[3][j];
		sort(s1,s1+c1);
		sort(s2,s2+c2);
		int i;
		for(i=0;i<n;i++)
			if(ok(-a[4][i]))
				break;
		if(i<n)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
