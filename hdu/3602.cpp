#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int f[10020];
int t,n,m,k,x,y;
int cal(int x,int y)
{
	if((x+k-1)/k==(x+y+k-1)/k)
		return x+y;
	return (x+k-1)/k*k+y;
}
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d %d",&n,&m,&k);
		memset(f,0x3f,sizeof f);
		f[0]=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&x,&y);
			x++;
			for(int j=10000;j>=y;j--)
				f[j]=min(f[j],cal(f[j-y],x));
		}
		int z=10000;
		while(f[z]>m*k)
			z--;
		printf("%d\n",z);
	}
	return 0;
}
