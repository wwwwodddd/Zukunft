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
int f[10020];
int a,b,c,n,m;
int F(int x)
{
	for(int i=m;i>=x;i--)
		f[i]|=f[i-x];
}
int main()
{
	for(;scanf("%d %d %d",&a,&b,&c),a+b+c;)
	{
		memset(f,0,sizeof f);
		f[0]=1;
		m=a+2*b+5*c;
		int i;
		for(i=0;1<<i<=a;a-=1<<i++)
			F((1<<i)*1);
		F(a*1);
		for(i=0;1<<i<=b;b-=1<<i++)
			F((1<<i)*2);
		F(b*2);
		for(i=0;1<<i<=c;c-=1<<i++)
			F((1<<i)*5);
		F(c*5);
		for(i=0;i<=m+1;i++)
			if(!f[i])
			{
				printf("%d\n",i);
				break;
			}
	}
}
