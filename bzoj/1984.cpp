#include<stdio.h>
#include<iostream>
#define BUFSIZE 10000000
char buf[BUFSIZE],*pt=buf;
int sign;
#define scan(t)\
{\
	t=0;sign=1;\
	while((*pt<'0'||*pt>'9')&&*pt!='-')\
		 pt++;\
	if(*pt=='-')\
		sign=-1,pt++;\
	while(*pt>='0'&&*pt<='9')\
		t=t*10+(*pt++)-'0';\
	t*=sign;\
}
#define scan_str(s)\
{\
	int p=0;\
	while(*pt==' '||*pt=='\n')\
		pt++;\
	while(!(*pt==' '||*pt=='\n'))\
		s[p++]=*pt++;\
	s[p]=0;\
}
using namespace std;
struct N
{
	int l,r,mx,ad,sa;
	N(){}
	N(int l,int r,int mx):l(l),r(r),mx(mx){ad=sa=0;}
}t[300000];
N operator+(const N &a,const N &b)
{
	return N(a.l,b.r,max(a.mx,b.mx));
}
int a[300000][3],h[300000],tot;
int w[300000];
int l[300000];
int u[300000];
int b[300000];
int f[300000];
int d[300000];
int p[300000];
int cnt;
void mt(int x,int l,int r)
{
	if(l==r)
	{
		t[x].l=l;
		t[x].r=r;
		t[x].mx=w[b[l]];
		return;
	}
	int m=(l+r)>>1;
	mt(x*2,l,m);
	mt(x*2+1,m+1,r);
	t[x]=t[2*x]+t[2*x+1];
	return;
}
void add(int x,int y,int z)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	a[tot][2]=z;
	h[x]=tot;
}
void pd(int x)
{
	if(t[x].l==t[x].r)
		return;
	if(t[x].sa)
	{
		t[2*x].mx=t[2*x+1].mx=t[x].mx;
		t[2*x].sa=t[2*x+1].sa=1;
		t[x].sa=0;
		t[x].ad=0;
	}
	if(t[x].ad)
	{
		t[2*x].mx+=t[x].ad;
		t[2*x].ad+=t[x].ad;
		t[2*x+1].mx+=t[x].ad;
		t[2*x+1].ad+=t[x].ad;
		t[x].ad=0;
	}
}
void dfs(int x)
{
	u[x]=1;
	int i,k=0,e,z;
	for(i=h[x];i;i=a[i][0])
		if((e=a[i][1])!=f[x])
		{
			f[e]=x;
			w[e]=a[i][2];
			d[e]=d[x]+1;
			dfs(e);
			if(u[e]>k)
				k=u[z=e];
			u[x]+=u[e];
		}
	if(k)
		l[z]=1;
}
void bd(int x)
{
	if(l[x])
		l[x]=l[f[x]];
	else
		l[x]=x;
	int i,flag=0;
	for(i=h[x];i;i=a[i][0])
		if(a[i][1]!=f[x])
			flag=1,bd(a[i][1]);
	if(!flag)
	{
		int j;
		for(j=x;l[j]!=j;j=f[j])
			b[++cnt]=j;
		b[++cnt]=j;
	}
}
void R(int ll,int rr,int cc,int x=1)
{
	if(t[x].l>=ll&&t[x].r<=rr)
	{
		t[x].mx=t[x].mx=cc;
		t[x].sa=1;
		return;
	}
	pd(x);
	int m=(t[x].l+t[x].r)>>1;
	if(ll>m)
		R(ll,rr,cc,x*2+1);
	else if(rr<=m)
		R(ll,rr,cc,x*2);
	else
		R(ll,rr,cc,x*2),R(ll,rr,cc,x*2+1);
	t[x]=t[2*x]+t[2*x+1];
}
void S(int ll,int rr,int cc,int x=1)
{
	if(t[x].l>=ll&&t[x].r<=rr)
	{
		t[x].mx+=cc;
		t[x].ad+=cc;
		return;
	}
	pd(x);
	int m=(t[x].l+t[x].r)>>1;
	if(ll>m)
		S(ll,rr,cc,x*2+1);
	else if(rr<=m)
		S(ll,rr,cc,x*2);
	else
		S(ll,rr,cc,x*2),S(ll,rr,cc,x*2+1);
	t[x]=t[2*x]+t[2*x+1];
}
N F(int ll,int rr,int x=1)
{
	pd(x);
	if(t[x].l>=ll&&t[x].r<=rr)
		return t[x];
	int m=(t[x].l+t[x].r)>>1;
	if(rr<=m)
		return F(ll,rr,x*2);
	if(ll>m)
		return F(ll,rr,x*2+1);
	return F(ll,rr,x*2)+F(ll,rr,x*2+1);
}
void C(int a,int b,int c)
{
	while(l[a]!=l[b])
	{
		if(d[l[a]]<d[l[b]])
			swap(a,b);
		R(p[a],p[l[a]],c);
		a=f[l[a]];
	}
	if(p[a]<p[b])
		R(p[a],p[b]-1,c);
	else if(p[b]<p[a])
		R(p[b],p[a]-1,c);
	return;
}
void A(int a,int b,int c)
{
	while(l[a]!=l[b])
	{
		if(d[l[a]]<d[l[b]])
			swap(a,b);
		S(p[a],p[l[a]],c);
		a=f[l[a]];
	}
	if(p[a]<p[b])
		S(p[a],p[b]-1,c);
	else if(p[b]<p[a])
		S(p[b],p[a]-1,c);
	return;
}
N G(int a,int b)
{
	N re=N(0,0,0);
	while(l[a]!=l[b])
	{
		if(d[l[a]]<d[l[b]])
			swap(a,b);
		re=re+F(p[a],p[l[a]]);
		a=f[l[a]];
	}
	if(p[a]<p[b])
		re=re+F(p[a],p[b]-1);
	else if(p[b]<p[a])
		re=re+F(p[b],p[a]-1);
	return re;
}
int n,m,i,x,y,z;
char o[9];
int main()
{
	freopen("c.in","r",stdin);
	fread(buf,1,BUFSIZE,stdin);
	scan(n);
	for(i=1;i<n;i++)
	{
		scan(x);
		scan(y);
		scan(z);
		add(x,y,z);
		add(y,x,z);
	}
	dfs(1);
	bd(1);
	for(i=1;i<=cnt;i++)
		p[b[i]]=i;
	mt(1,1,cnt);
	while(1)
	{
		scan_str(o);
		if(*o=='S')
			break;
		if(*o=='C'&&o[1]=='o')
		{
			scan(x);
			scan(y);
			scan(z);
			C(x,y,z);
		}
		else if(*o=='C'&&o[1]=='h')
		{
			scan(x);
			scan(z);
			C(a[2*x][1],a[2*x-1][1],z);
		}
		else if(*o=='A')
		{
			scan(x);
			scan(y);
			scan(z);
			A(x,y,z);
		}
		else if(*o=='M')
		{
			scan(x);
			scan(y);
			printf("%d\n",G(x,y).mx);
		}
	}
	return 0;
}