#include<stdio.h>
#include<iostream>
#define L a[0]
#define R a[1]
using namespace std;
struct N *rt,*O;
struct N
{
	int sz;
	N *a[2],*f;
	N()
	{
		sz=1;
		L=R=f=O;
	}
	int d()
	{
		return f->R==this;
	}
	void sc(N *y,int z)
	{
		a[z]=y;
		y->f=this;
	}
	void ud()
	{
		sz=L->sz+1+R->sz;
	}
	void rtt()
	{
		N *p=f;
		int c=d();
		p->sc(a[!c],c);
		p->f->sc(this,p->d());
		sc(p,!c);
		p->ud();
		if(rt==p)
			rt=this;
	}
	void spy(N *y)
	{
		for(;f!=y;rtt())
			if(f->f!=y)
				d()==f->d()?f->rtt():rtt();
		ud();
	}
}t[1000020];
int a[1000020];
N *mt(int l,int r)
{
	if(l>r)
		return O;
	N *re=t+a[(l+r)/2];
	re->sc(mt(l,(l+r)/2-1),0);
	re->sc(mt((l+r)/2+1,r),1);
	re->ud();
	return re;
}
void sct(int x,N *f)
{
	N *p=rt;
	for(;;)
	{
		int j=p->L->sz;
		if(x==j)
			return p->spy(f);
		p=p->a[x>j];
		if(x>j)
			x-=j+1;
	}
}
void init()
{
	O=t;
	O->sz=0;
	rt=new N;
	rt->sc(new N,1);
}
N *get(int x,int y)
{
	sct(x-1,O);
	sct(y+1,rt);
	return rt->R->L;
}
int del(N *r)
{
	r->spy(O);
	int j=rt->L->sz;
	get(j,j);
	rt->R->sc(O,0);
	return j;
}
int main()
{
	int n,m,x,y,z;
	char o[20];
	init();
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	rt->R->sc(mt(1,n),0);
	rt->R->spy(O);
	while(m--)
	{
		scanf("%s",o);
		if(*o=='T')
		{
			scanf("%d",&x);
			del(t+x);
			get(1,0);
			rt->R->sc(t+x,0);
			rt->R->spy(O);
		}
		else if(*o=='B')
		{
			scanf("%d",&x);
			del(t+x);
			get(n,n-1);
			rt->R->sc(t+x,0);
			rt->R->spy(O);
		}
		else if(*o=='I')
		{
			scanf("%d %d",&x,&y);
			int j=del(t+x);
			get(j+y,j+y-1);
			rt->R->sc(t+x,0);
			rt->R->spy(O);
		}
		else if(*o=='A')
		{
			scanf("%d",&x);
			(t+x)->spy(O);
			printf("%d\n",rt->L->sz-1);
		}
		else if(*o=='Q')
		{
			scanf("%d",&x);
			sct(x,O);
			printf("%d\n",rt-t);
		}
	}
	return 0;
}
