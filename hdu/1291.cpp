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
	int a[300],l;
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
	}
};
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
Int operator-(const Int &a,const Int &b)
{
	Int re;
	int x=0,i;
	for(i=0;i<a.l;i++)
	{
		re[i]=a[i]-b[i]-x;
		if(re[i]<0)
			re[i]+=10000,x=1;
		else
			x=0;
	}
	re.l=a.l;
	while(re.l>1&&!re[re.l-1])
		re.l--;
	return re;
}
Int operator*(const Int &a,const Int &b)
{
	Int re;
	for(int i=0;i<a.l;i++)
		for(int j=0;j<b.l;j++)
		{
			re[i+j]+=a[i]*b[j];
			re[i+j+1]+=re[i+j]/10000;
			re[i+j]%=10000;
		}
	re.l=a.l+b.l;
	while(re.l>1&&!re[re.l-1])
		re.l--;
	return re;
}
Int operator/(const Int &a,int b)
{
	Int re;
	int x=0;
	for(int i=a.l;i--;)
	{
		re[i]=(x*10000+a[i])/b;
		x=(x*10000+a[i])%b;
	}
	re.l=a.l;
	while(re.l>1&&!re[re.l-1])
		re.l--;
	return re;
}
Int ans;
int n;
int main()
{
	while(~scanf("%d",&n))
	{
		ans=1;
		for(int i=1;i<=n*n;i++)
			ans=ans*i;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				ans=ans/(i+j+1);
		ans.print();
		puts("");
	}
	return 0;
}
