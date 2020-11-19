#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int f[1020],c[1020],w[1020];
int t,n,m,v;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;i++)
			scanf("%d",c+i);
		for(int i=0;i<n;i++)
			scanf("%d",w+i);
		memset(f,0,sizeof f);
		for(int i=0;i<n;i++)
			for(int j=m;j>=w[i];j--)
				f[j]=max(f[j],f[j-w[i]]+c[i]);
		printf("%d\n",f[m]);
	}
	return 0;
}
