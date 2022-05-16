#include<stdio.h>
#include<iostream>
#define RT(x) (L(F(x))!=x&&R(F(x))!=x)
using namespace std;
struct N
{
	int rv,a[2],f;
#define V(x) t[x].rv
#define L(x) t[x].a[0]
#define R(x) t[x].a[1]
#define F(x) t[x].f
}t[100020];
int d(int x)
{
	return R(F(x))==x;
}
void sc(int x,int y,int z)
{
	t[x].a[z]=y;
	F(y)=x;
}
void rev(int x)
{
	swap(L(x),R(x));
	V(x)^=1;
}
void pd(int x)
{
	if(V(x))
		rev(L(x)),rev(R(x)),V(x)=0;
}
void rtt(int x)
{
	int p=F(x);
	int c=d(x);
	pd(F(x));
	pd(x);
	sc(p,t[x].a[!c],c);
	F(x)=F(p);
	if(!RT(p))
		sc(F(p),x,d(p));
	sc(x,p,!c);
}
void spy(int x)
{
	for(pd(x);!RT(x);rtt(x))
		if(!RT(F(x)))
			d(x)==d(F(x))?rtt(F(x)):rtt(x);
}
int acs(int x)
{
	for(int z=0;x;z=x,x=F(x))
	{
		spy(x);
		R(x)=z;
		if(!F(x))
		{
			while(L(x))
				x=L(x);
			return x;
		}
	}
	return 0;
}
void cut(int x,int y)
{
	acs(x);
	spy(y);
	if(R(y)==x)
		R(y)=F(x)=0;
	else
		F(y)=0;
}
void lnk(int x,int y)
{
	acs(x);
	spy(x);
	rev(x);
	F(x)=y;
}
int main()
{
	int n,m,x,y,z;
	char o[10];
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%s %d %d",o,&x,&y);
		if(*o=='a')
			lnk(x,y);
		else if(*o=='r')
			cut(x,y);
		else if(*o=='c')
			puts(acs(x)==acs(y)?"YES":"NO");
	}
}