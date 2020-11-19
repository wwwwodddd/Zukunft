#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define p 19940417
struct N
{
	int l,r,rv,ad;
	int a[21];
}t[140000];
int a[50020];
int c[50020][21];
int qqq;
void add(int a[],int b[],int c[],int u=20)
{
	static long long w[21];
	for(int i=0;i<=u;i++)
		w[i]=0;
	for(int i=0;i<=u;i++)
		for(int j=0;i+j<=u;j++)
			w[i+j]+=(long long)b[i]*c[j];
	for(int i=0;i<=u;i++)
		a[i]=w[i]%p;
}
void rev(int x)
{
	for(int i=1;i<21;i+=2)
		t[x].a[i]=-t[x].a[i];
	t[x].rv^=1;
	t[x].ad=-t[x].ad;
}
void add(int x,int z)
{
	int len=t[x].r-t[x].l+1;
	register int pw[21];
	pw[0]=1;
	for(int i=1;i<21&&i<=len;i++)
		pw[i]=(long long)pw[i-1]*z%p;
	N&q=t[x];
	q.ad+=z;
	if(q.ad>=p)
		q.ad-=p;
	static long long w[21];
	for(int i=0;i<21&&i<=len;i++)
		w[i]=0;
	for(int i=0;i<21&&i<=len;i++)
		for(int j=0;j<i;j++)
			w[i]+=(long long)q.a[j]*c[len-j][i-j]%p*pw[i-j];
	for(int i=0;i<21&&i<=len;i++)
		q.a[i]=(q.a[i]+w[i])%p;
	return;
}
void pd(int x)
{
	if(t[x].l==t[x].r)
		return;
	if(t[x].rv)
	{
		t[x].rv=0;
		rev(2*x);
		rev(2*x+1);
	}
	if(t[x].ad)
	{
		add(x*2,t[x].ad);
		add(x*2+1,t[x].ad);
		t[x].ad=0;
	}
}
void rev(int x,int l,int r)
{
	if(l<=t[x].l&&t[x].r<=r)
	{
		rev(x);
		return;
	}
	else if(t[x].r<l||t[x].l>r)
		return;
	pd(x);
	int L=x*2,R=L+1;
	rev(L,l,r);
	rev(R,l,r); 
	add(t[x].a,t[L].a,t[R].a);
}
void bd(int x,int l,int r)
{
	t[x].l=l;
	t[x].r=r;
	if(l==r)
	{
		t[x].a[0]=1;
		t[x].a[1]=a[l];
		return;
	}
	int m=l+r>>1;
	int L=x*2,R=L+1;
	bd(L,l,m);
	bd(R,m+1,r);
	add(t[x].a,t[L].a,t[R].a);
}
void ask(int z[],int x,int l,int r)
{
	if(l<=t[x].l&&t[x].r<=r)
	{
		for(int i=0;i<=qqq;i++)
			z[i]=t[x].a[i];
		return;
	}
	else if(t[x].r<l||t[x].l>r)
	{
		z[0]=1;
		for(int i=1;i<=qqq;i++)
			z[i]=0;
		return;
	}
	int zl[21],zr[21];
	pd(x);
	int L=x*2,R=L+1;
	ask(zl,L,l,r);
	ask(zr,R,l,r);
	add(z,zl,zr,qqq);
	return;
}
void add(int x,int l,int r,int z)
{
	if(l<=t[x].l&&t[x].r<=r)
	{
		add(x,z);
		return;
	}
	else if(t[x].r<l||t[x].l>r)
		return;
	pd(x);
	add(x*2,l,r,z);
	add(x*2+1,l,r,z);
	add(t[x].a,t[x*2].a,t[x*2+1].a);
}
int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		a[i]%=p;
		if(a[i]<0)
			a[i]+=p;
	}
	bd(1,1,n);
	for(int i=0;i<=n;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i&&j<=20;j++)
		{
			c[i][j]=(c[i-1][j]+c[i-1][j-1]);
			if(c[i][j]>=p)
				c[i][j]-=p;
		}
	}
	for(int i=0;i<q;i++)
	{
		char o[5];
		int x,y;
		scanf("%s %d %d",&o,&x,&y); 
		if(*o=='I')
		{
			int z;
			scanf("%d",&z);
			z%=p;
			if(z<0)
				z+=p;
			add(1,x,y,z);
		}
		else if(*o=='R')
		{
			rev(1,x,y);
		}
		else if(*o=='Q')
		{
			scanf("%d",&qqq);
			int ans[21];
			ask(ans,1,x,y);
			if(ans[qqq]<0)
				ans[qqq]+=p;
			printf("%d\n",ans[qqq]);
		}
	}
	return 0;
}
