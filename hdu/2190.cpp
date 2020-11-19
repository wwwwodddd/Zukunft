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
int f[40];
int n,t;
int main()
{
	f[1]=1;
	for(int i=2;i<=35;i++)
		f[i]=f[i-1]+2*f[i-2];
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		printf("%d\n",f[n+1]);
	}
}
