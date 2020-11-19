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
int f[1020]={1,2};
int g[1020];
int v[1020];
int n,m,p;
int main()
{
	for(int i=2;i<20;i++)
		f[i]=f[i-1]+f[i-2];
	for(int i=1;i<1001;i++)
	{
		for(int j=0;f[j]<=i;j++)
			v[g[i-f[j]]]=i;
		for(;v[g[i]]==i;)
			g[i]++;
	}
	while(scanf("%d %d %d",&n,&m,&p),n+m+p)
		puts(g[n]^g[m]^g[p]?"Fibo":"Nacci");
}
