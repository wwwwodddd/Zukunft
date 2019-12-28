#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
int n,s;
int c[12],a[12];
int C(int n,int m)
{
	int re=1,i;
	for(i=1;i<=m;i++)
	{
		re*=n-m+i;
		re/=i;
	}
	return re;
}
int ck()
{
	int i,o=0;
	for(i=0;i<n;i++)
		o+=a[i]*c[i];
	return o==s;
}
int main()
{
	int i;
	scanf("%d %d",&n,&s);
	for(i=0;i<n;i++)
		a[i]=i+1,c[i]=C(n-1,i);
	while(1)
	{
		if(ck())
		{
			for(i=0;i<n;i++)
				printf("%d ",a[i]);
			break;
		}
		next_permutation(a,a+n);
	}
	return 0;
}