#include<stdio.h>
#include<iostream>
#define L a[0]
#define R a[1]
using namespace std;
typedef long long ll;
struct N *O,*rt;
struct N
{
	int sa,sz;
	ll sm,w,A,B;
	N *a[2],*f;
	int d()
	{
		return f->R==this;
	}
	void sc(N *y,int z)
	{
		a[z]=y;
		y->f=this;
	}
	N *set(int k)
	{
		sm=w=k;
		A=B=0;
		sa=0;
		sz=1;
		L=R=f=O;
		return this;
	}
	void add(ll A,ll B)
	{
		sm+=A*sz+B*sz*(sz-1)/2;
		w+=A+L->sz*B;
		this->A+=A;
		this->B+=B;
	}
	void sam(int u)
	{
		if(this==O)
			return;
		w=u;
		sm=(ll)u*sz;
		A=B=0;
		sa=u;
	}
	void ud()
	{
		sz=L->sz+1+R->sz;
		sm=L->sm+w+R->sm;
	}
	void pd()
	{
		if(sa)
			L->sam(sa),R->sam(sa),sa=0;
		if(A||B)
			L->add(A,B),R->add(A+B*(L->sz+1),B),A=B=0;
	}
	void rtt()
	{
		N *p=f;
		int c=d();
		p->pd();
		pd();
		p->sc(a[!c],c);
		p->f->sc(this,p->d());
		sc(p,!c);
		p->ud();
		if(rt==p)
			rt=this;
	}
	void spy(N*y)
	{
		for(pd();f!=y;rtt())
			if(f->f!=y)
				d()==f->d()?f->rtt():rtt();
		ud();
	}
}t[1000020],*tt=t;
int a[1000020];
N *mlc(int k)
{
	return tt++->set(k);
}
void sct(int x,N *f)
{
	N *p=rt;
	for(;;)
	{
		p->pd();
		int j=p->L->sz;
		if(j==x)
			return p->spy(f);
		p=p->a[x>j];
		if(x>j)
			x-=j+1;
	}
}
N *mt(int l,int r)
{
	if(l>r)	
		return O;
	N *re=mlc(a[l+r>>1]);
	re->sc(mt(l,(l+r)/2-1),0);
	re->sc(mt((l+r)/2+1,r),1);
	re->ud();
	return re;
}
void init()
{
	O=mlc(-1);
	O->sm=O->sz=0;
	rt=mlc(-1);
	rt->sc(mlc(-1),1);
}
N *get(int l,int r)
{
	sct(l-1,O);
	sct(r+1,rt);
	return rt->R->L;
}
int main()
{
	int n,m,x,y,z,o;
	scanf("%d %d",&n,&m);
	init();
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	rt->R->sc(mt(1,n),0);
	rt->R->spy(O);
	while(m--)
	{
		scanf("%d",&o);
		if(o==1)
		{
			scanf("%d %d %d",&x,&y,&z);
			get(x,y)->sam(z);
			rt->R->spy(O);
		}
		else if(o==2)
		{
			scanf("%d %d %d",&x,&y,&z);
			get(x,y)->add(z,z);
			rt->R->spy(O);
		}
		else if(o==3)
		{
			scanf("%d %d",&x,&y);
			get(x,x-1);
			rt->R->sc(mlc(y),0);
			rt->R->spy(O);
		}
		else
		{
			scanf("%d %d",&x,&y);
			printf("%lld\n",get(x,y)->sm);
		}
	}
	return 0;
}
