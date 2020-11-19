#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(i=0;i<n;i++)
#define fo(i,n) for(i=1;i<=n;i++)
int scan()
{
	int _=0;
	char c;
	while(!((c=getchar())>='0'&&c<='1'))
		;
	_=c-'0';
	while((c=getchar())>='0'&&c<='1')
	_=_*2+c-'0';
	return _;
}
int print(int x)
{
	if(x>>1)
		print(x>>1);
	putchar('0'+x%2);
}
int a[110],b[110];
int i,j,n,m,z=-1;
int main()
{
	scanf("%d %d",&n,&m);
	fr(i,m)
	{
		a[i]=scan();
		scanf("%d",b+i);
	}
	fr(i,(1<<n)&&z>-2)
	{
		fr(j,m)
			if(__builtin_popcount(i&a[j])!=b[j])
				break;
		if(j==m)
			if(~z)
				z=-2;
			else
				z=i;
	}
	if(z<0)
		puts(~z?"NOT UNIQUE":"IMPOSSIBLE");
	else
		print(z);
	return 0;
}
