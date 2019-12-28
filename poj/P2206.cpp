#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int a[10020];
int f[1020];
int v[1020];
int p[1020];
int o[1020];
int z[1020],zc;
int n,m,nx;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	f[1]=1;
	for(int i=0;i<n;i++)
	{
		memset(v,0,sizeof v);
		for(int j=0;j<m;j++)
			if(f[j]&&!v[j]&&!f[j*a[i]%m])
			{
				nx=j*a[i]%m;
				v[nx]=f[nx]=1;
				p[nx]=j;
				o[nx]=i;
			}
	}
	for(;!f[m];m--)
		;
	printf("%d\n",m);
	for(;m>1;m=p[m])
		z[zc++]=o[m];
	for(;zc--;)
		printf("%d ",z[zc]+1);
	return 0;
}
