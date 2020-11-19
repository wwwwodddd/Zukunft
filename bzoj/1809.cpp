#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define inf 0x7fffffff
using namespace std;
struct N
{
	int mx,sm,sa;
	N *l,*r;
}t[1000000];
N *tt=t;
N *mlc()
{
	tt++;
	tt->sa=0;
	tt->l=tt->r=0;
	return tt;
}
void pd(N *x,int l,int r)
{
	if(l==r||x->sa==inf)
		return;
	if(x->l==0)
		x->l=mlc();
	x->l->sm=x->sa*((l+r)/2-l+1);
	x->l->mx=max(x->l->sm,0);
	x->l->sa=x->sa;
	if(x->r==0)
		x->r=mlc();
	x->r->sm=x->sa*(r-(l+r)/2);
	x->r->mx=max(x->r->sm,0);
	x->r->sa=x->sa;
	x->sa=inf;
	return;
}
void R(N *v,int l,int r,int x,int y,int z)
{
	pd(v,l,r);
	int m=(l+r)/2;
	if(x<=l&&y>=r)
	{
		v->sa=z;
		v->sm=v->sa*(r-l+1);
		v->mx=max(v->sm,0);
		return;
	}
	else if(x>m)
		R(v->r,m+1,r,x,y,z);
	else if(y<=m)
		R(v->l,l,m,x,y,z);
	else
		R(v->r,m+1,r,x,y,z),R(v->l,l,m,x,y,z);
	v->sm=v->l->sm+v->r->sm;
	v->mx=max(v->l->mx,v->l->sm+v->r->mx);
	return;
}
int A(N *v,int l,int r,int z)
{
	int re=0;
	if(v->sa!=inf)
	{
		if(v->sa>0)
			re=min(l+z/v->sa,r+1);
		else
			re=r+1;
		return re;
	}
	int m=(l+r)/2;
	if(z>=v->l->mx)
		return A(v->r,m+1,r,z-v->l->sm);
	else
		return A(v->l,l,m,z);
}
int n;
char o[5];
int main()
{
	int x,y,z;
	scanf("%d",&n);
	while(1)
	{
		scanf("%s",o);
		if(*o=='E')
			break;
		if(*o=='Q')
		{
			scanf("%d",&z);
			printf("%d\n",A(t,1,n,z)-1);
		}
		if(*o=='I')
		{
			scanf("%d %d %d",&x,&y,&z);
			R(t,1,n,x,y,z);
		}
	}
	return 0;
}