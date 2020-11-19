#include<stdio.h>
#include<iostream>
using namespace std;
int a[10020],n,k,ans;
int l[10020][105];
int r[10020][105];
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int j=1;j<=k;j++)
		for(int i=1;i<=n;i++)
			l[i][j]=l[i-1][j]+(a[i]!=-1&&a[i]>j);
	for(int j=1;j<=k;j++)
		for(int i=n;i>0;i--)
			r[i][j]=r[i+1][j]+(a[i]!=-1&&a[i]<j);
	for(int i=1;i<=n;i++)
		if(a[i]==-1)
		{
			int z=0xffffff;
			for(int j=1;j<=k;j++)
				z=min(z,l[i][j]+r[i][j]);
			ans+=z*2;
		}
		else 
			ans+=l[i][a[i]]+r[i][a[i]];
	printf("%d",ans/2);
	return 0;
}
