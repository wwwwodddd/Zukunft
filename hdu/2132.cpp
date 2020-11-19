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
long long a[100020];
int n;
int main()
{
	for(int i=1;i<100020;i++)
		if(i%3)
			a[i]=a[i-1]+i;
		else
			a[i]=a[i-1]+(long long)i*i*i;
	for(;scanf("%d",&n),n>=0;)
		printf("%I64d\n",a[n]);
}
