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
int t,n,m;
int f[220];
int P(int x)
{
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return 0;
	return 1;	
}
int main()
{
	f[0]=1;
	for(int i=2;i<200;i++)
		if(P(i))
			for(int j=i;j<200;j++)
				f[j]+=f[j-i];
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		printf("%d\n",f[n]);
	}
}

