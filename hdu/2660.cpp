#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
int f[30][1020];
int w[30],v[30];
int n,m,l,t;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d",&n,&l);
		fr(i,n)
			scanf("%d %d",v+i,w+i);
		scanf("%d",&m);
		memset(f,0xc0,sizeof f);
		memset(f,0,sizeof f[0]);
		fr(i,n)
			for(int j=l;j;j--)
				for(int k=w[i];k<=m;k++)
					f[j][k]=max(f[j][k],f[j-1][k-w[i]]+v[i]);
		printf("%d\n",f[l][m]);
	}
}
