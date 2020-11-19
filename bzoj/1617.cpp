#include<stdio.h>
#include<iostream>
using namespace std;
int f[3020];
int i,j,n;
int main()
{
	scanf("%d %d",&n,&f[0]);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&f[i]);
		f[i]+=f[i-1];
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=i/2;j++)
			f[i]=min(f[i],f[j]+f[i-j]+f[0]);
	printf("%d",f[n]);
	return 0;
}