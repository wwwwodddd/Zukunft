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
int f[40000],n;
int main()
{
	f[0]=1;
	for(int j=1;j<4;j++)
		for(int i=j;i<=32768;i++)
			f[i]+=f[i-j];
	for(;scanf("%d",&n)+1;)
		printf("%d\n",f[n]);
}
