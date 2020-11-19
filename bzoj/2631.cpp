#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#define RT(x) (L(F(x))!=x&&R(F(x))!=x)
using namespace std;
typedef long long ll;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int mo=51061;
struct N
{
	int w,sm,mu,ad,rv,sz,a[2],f;
#define W(x) t[x].w
#define S(x) t[x].sm
#define M(x) t[x].mu
#define A(x) t[x].ad
#define V(x) t[x].rv
#define Z(x) t[x].sz
#define L(x) t[x].a[0]
#define R(x) t[x].a[1]
#define F(x) t[x].f
}t[100020];
int h[100020];
int a[200020][2],tot;
void dfs(int x,int y)
{
	F(x)=y;
	for(int i=h[x];i;i=a[i][0])
		if(a[i][1]!=y)
			dfs(a[i][1],x);
}
void edg(int x,int y)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	h[x]=tot;	
}
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
void ud(int x)
{
	Z(x)=Z(L(x))+1+Z(R(x));
	S(x)=S(L(x))+W(x)+S(R(x));
}
void mul(int x,int y)
{
	if(!x)
		return;
	M(x)=(ll)M(x)*y%mo;
	A(x)=(ll)A(x)*y%mo;
	W(x)=(ll)W(x)*y%mo;
	S(x)=(ll)S(x)*y%mo;
}
void add(int x,int y)
{
	if(!x)
		return;
	A(x)=(A(x)+y)%mo;
	W(x)=(W(x)+y)%mo;
	S(x)=(S(x)+Z(x)*y)*mo;
}
void pd(int x)
{
	if(M(x)!=1)
	{
		mul(L(x),M(x));
		mul(R(x),M(x));
		M(x)=1;
	}
	if(A(x)!=0)
	{
		add(L(x),A(x));
		add(R(x),A(x));
		A(x)=0;
	}
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
	ud(p);
}
void spy(int x)
{
	for(pd(x);!RT(x);)
		if(RT(F(x)))
			rtt(x);
		else
			d(x)==d(F(x))?rtt(F(x)):rtt(x),rtt(x);
	ud(x);
}
int acs(int x,int o=-1,int d=0)
{
	for(int z=0;x;z=x,x=F(x))
	{
		spy(x);
		if(!F(x))
		{
			if(o==0)
				return S(R(x))+S(z)+W(x);
			else if(o==1)
			{
				mul(R(x),d);
				mul(z,d);
				W(x)=(ll)W(x)*d%mo;
			}
			else if(o==2)
			{
				add(R(x),d);
				add(z,d);
				W(x)=(W(x)+d)%mo;
			}
		}
		R(x)=z;
		ud(x);
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
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout);
	int n,m,x,y,z;
	char o[10];
	scanf("%d %d",&n,&m);
	for(int i=1;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		edg(x,y);
		edg(y,x);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		W(i)=M(i)=1,ud(i);
	for(int i=0;i<m;i++)
	{
		scanf("%s %d %d",o,&x,&y);
		if(*o=='/')
			acs(x),printf("%d\n",acs(y,0));
		else if(*o=='*')
			scanf("%d",&z),acs(x),acs(y,1,z);
		else if(*o=='+')
			scanf("%d",&z),acs(x),acs(y,2,z);
		else
			cut(x,y),scanf("%d %d",&x,&y),lnk(x,y);
	}
	while(1);
	return 0;
}
