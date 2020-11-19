#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int a[30],s[30];
int n,z;
void dfs(int x,int y,int z)
{
	if(!x)
	{
		if(!y)
			::z=min(::z,z);
		return;
	}
	if(abs(y)>s[x])
		return;
	dfs(x-1,y-a[x],z);
	dfs(x-1,y+a[x],z);
	dfs(x-1,y,z+a[x]);
}
int main()
{
	for(;scanf("%d",&n),n;)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++)
			s[i]=s[i-1]+a[i];
		z=1<<30;
		dfs(n,0,0);
		printf("%d\n",z);
	}
	return 0;
}
