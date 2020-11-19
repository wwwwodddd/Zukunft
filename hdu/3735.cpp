#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<time.h>
#define mo 1000000003
using namespace std;
int t,n,m;
long long a[2020],b[2020],c[2020],f[2020];
int tim;
void mul(long long a[2020],long long b[2020],long long c[2020])
{
	long long _[2020];
	memset(_,0,sizeof _);
	for(int i=0;i<n;i++)
		if(a[i])
		for(int j=0;j<n;j++)
			tim++,
			_[i+j]=(_[i+j]+a[i]*b[j])%mo;
	for(int i=2*n-2;i>=n;i--)
		if(_[i])
			for(int j=0;j<n;j++)
				tim++,
				_[i-n+j]=(_[i-n+j]+_[i]*f[j])%mo;
	memset(c,0,sizeof _);
	for(int i=0;i<n;i++)
		c[i]=_[i];
}
long long z;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d",&n,&m);
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(c,0,sizeof c);
		memset(f,0,sizeof f);
		for(int i=0;i<n;i++)
			scanf("%I64d",a+i);
		for(int i=0;i<n;i++)
			scanf("%I64d",f+i);
		c[0]=1;
		if(n>1)
			b[1]=1;
		else
			b[0]=f[0];
		z=0;
		for(;m;m>>=1)
		{
			if(m&1)
				mul(c,b,c);
			mul(b,b,b);
		}
		for(int i=0;i<n;i++)
			z=(z+a[i]*c[i])%mo;
		printf("%I64d\n",(z+mo)%mo);
	}
}
