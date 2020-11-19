#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#define L a[0]
#define R a[1]
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
typedef pair<int,int> ii;
struct N *rt,*O;
struct N
{
	int rv,sz;
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
	void ud()
	{
		sz=L->sz+1+R->sz;
	}
	void pd()
	{
		if(rv)
			L->rev(),R->rev(),rv=0;
	}
	void rev()
	{
		swap(L,R);
		rv^=1;
	}
	void rtt()
	{
		int c=d();
		N *p=f;
		p->pd();
		pd();
		p->sc(a[!c],c);
		p->f->sc(this,p->d());
		sc(p,!c);
		p->ud();
		if(rt==p)
			rt=this;
	}
	void spy(N *y)
	{
		for(pd();f!=y;rtt())
			if(f->f!=y)
				d()==f->d()?f->rtt():rtt();
		ud();
	}
}t[100020],*tt;
int a[100020];
ii l[100020];
N *p[100020];
N *alc()
{
	N *re=tt++;
	re->rv=0;
	re->sz=1;
	re->L=re->R=re->f=O;
	return re;
}
N *mt(int l,int r)
{
	if(l>r)
		return O;
	N *re=alc();
	re->sc(mt(l,(l+r)/2-1),0);	
	re->sc(mt((l+r)/2+1,r),1);	
	re->ud();
	return p[a[(l+r)/2]]=re;
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
void init()
{
	tt=t;
	O=alc();
	O->sz=0;
	rt=alc();
	rt->sc(alc(),1);
}
N *get(int x,int y)
{
	sct(x-1,O);
	sct(y+1,rt);
	return rt->R->L;
}
int main()
{
	for(int n;scanf("%d",&n),n;)
	{
		fo(i,n)
		{
			scanf("%d",a+i);
			l[i].first=a[i];
			l[i].second=i;
		}
		sort(l+1,l+1+n);
		fo(i,n)
			a[l[i].second]=i;
		init();
		rt->R->sc(mt(1,n),0);
		rt->R->spy(O);
		for(int i=1;i<=n;i++)
		{
			p[i]->spy(O);
			printf("%d%c",p[i]->L->sz,i==n?'\n':' ');
			get(i,p[i]->L->sz)->rev();
		}
	}
}
