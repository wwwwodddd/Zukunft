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
struct Int
{
	int a[1020],l;
	Int(int x=0)
	{
		memset(this,0,sizeof(Int));
		a[0]=x;
		l=1;
	}
	void scan()
	{
		char s[2020]={};
		scanf("%s",s);
		int t;
		for(t=0;s[t];t++)
			s[t]-='0';
		reverse(s,s+t);
		for(l=0;l*4<t;l++)
			a[l]=s[l*4]+s[l*4+1]*10+s[l*4+2]*100+s[l*4+3]*1000;
	}
	int &operator[](int i)
	{
		return a[i];
	}
	int operator[](int i)const
	{
		return a[i];
	}
	void print()
	{
		int i=l;
		printf("%d",a[--i]);
		while(i)
			printf("%04d",a[--i]);
		puts("");
	}
};
Int f[7100];
Int operator+(const Int &a,const Int &b)
{
	Int re;
	int x=0,i;
	for(i=0;i<max(a.l,b.l);i++)
	{
		re[i]=a[i]+b[i]+x;
		x=re[i]/10000;
		re[i]%=10000;
	}
	if(x)
		re[i++]=x;
	re.l=i;
	return re;
}
int n;
int main()
{
	f[1]=f[2]=f[3]=f[4]=1;
	for(int i=5;i<7070;i++)
		f[i]=f[i-1]+f[i-2]+f[i-3]+f[i-4];
	while(~scanf("%d",&n))
		f[n].print();
	return 0;
}
