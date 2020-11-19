#include<stdio.h>
#include<iostream>
#define fr(i,n) for(int i=0;i<n;i++)
#define RT(x) (L(F(x))!=x&&R(F(x))!=x)
using namespace std;
int h[500020];
int a[1000020][2],tot;
int q[500020],b,f;
struct N
{
	int sm,w;
#define S(x) t[x].sm
#define W(x) t[x].w
	int a[2],f;
#define L(x) t[x].a[0]
#define R(x) t[x].a[1]
#define F(x) t[x].f
}t[500020];
void add(int x,int y)
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
void ud(int x)
{
	S(x)=S(L(x))^W(x)^S(R(x));	
}
void rtt(int x)
{
	int p=F(x);
	int c=d(x);
	sc(p,t[x].a[!c],c);
	F(x)=F(p);
	if(L(F(p))==p)
		L(F(p))=x;
	if(R(F(p))==p)
		R(F(p))=x;
	sc(x,p,!c);
	ud(p);
}
void spy(int x)
{
	for(;!RT(x);)
		if(RT(F(x)))
			rtt(x);
		else	
			d(x)==d(F(x))?rtt(F(x)):rtt(x),rtt(x);
	ud(x);
}
int acs(int x,int y)
{
	for(int z=0;x;x=F(x))
	{
		spy(x);
		if(!F(x)&&y)
			return S(R(x))^S(z)^W(x);
		R(x)=z;
		ud(x);
		z=x;
	}
	return 0;
}
int main()
{
	int n,m,x,y;
	char o[10];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&t[i].w);
	for(int i=1;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		add(x,y);
		add(y,x);
	}
	q[f++]=1;
	while(b<f)
	{
		x=q[b++];
		for(int i=h[x];i;i=a[i][0])
			if(a[i][1]!=F(x))
			{
				t[a[i][1]].f=x;
				q[f++]=a[i][1];
			}
	}
	int q;
	for(scanf("%d",&q);q--;)
	{
		scanf("%s %d %d",o,&x,&y);
		if(*o=='C')
		{
			t[x].w=y;
			acs(x,0);	
		}
		else if(*o=='Q')
		{
			acs(y,0);
			puts(acs(x,1)?"Yes":"No");
		}
	}
	return 0;
}
