#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int s[400020];
int t,n,z,x;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		memset(s,0,sizeof s);
		for(int i=z=0;i<n;i++)
			scanf("%d",&x),s[2*x]++;
		for(int i=z=0;i<100010;i++)
		{
			z=max(z,n+s[i*2]);
			n-=s[i];
		}
		printf("%d\n",z);
	}
}
