#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int n,i,j,k,x;
int a[1000020],cnt;
int main()
{
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		for(j=1;j*j<x;j++)
			if(x%j==0)
			{
				a[cnt++]=j;
				a[cnt++]=x/j;
			}
		if(j*j==x)
			a[cnt++]=j;
	}
	sort(a,a+cnt);
	reverse(a,a+cnt);
	for(i=j=0;i<cnt;i=j)
	{
		while(a[i]==a[j])
			j++;
		if(j-i>=k)
		{
			printf("%d",a[i]);
			break;
		}
	}
	return 0;
}