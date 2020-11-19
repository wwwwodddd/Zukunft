#include<stdio.h>
#include<string.h>
#include<iostream>
#define L a[0]
#define R a[1]
using namespace std;
typedef unsigned long long ull;
ull g[100020];
struct N *O,*rt;
struct N
{
	ull h,w;
	int sz;
	N *a[2],*f;
	bool d()
	{
		return f->R==this;
	}
	void sc(N *y,int z)
	{
		a[z]=y;
		y->f=this;	
	}
	void set(int x)
	{
		w=h=x;
		sz=1;
		L=R=f=O;
	}
	void ud()
	{
		sz=L->sz+1+R->sz;
		h=L->h+w*g[L->sz]+R->h*g[L->sz+1];
	}
	void rtt()
	{
		N *p=f;
		int c=d();
		p->sc(a[!c],c);
		p->f->sc(this,p->d());
		sc(p,!c);
		p->ud();
		if(p==rt)
			rt=this;
	}
	void spy(N *y)
	{
		for(;f!=y;)
			if(f->f==y)
				rtt();
			else
				d()==f->d()?f->rtt():rtt(),rtt();
		ud();
	}
	void print()
	{
		if(this==O)
			return;
		L->print();
		printf("%c",w);
		R->print();
	}
}t[200020],*tt=t;
int a[200020];
char s[200020];
N *mlc(int x)
{
	N *re=tt++;
	re->set(x);
	return re;
}
void sct(int x,N *f)
{
	N *p=rt;
	for(;;)
	{
		int j=p->L->sz;
		if(j==x)
			break;
		p=p->a[x>j];
		if(x>j)
			x-=j+1;
	}
	p->spy(f);
}
N *mt(int l,int r)
{
	if(l>r)
		return O;
	N *re=mlc(a[(l+r)/2]);
	re->sc(mt(l,(l+r)/2-1),0);
	re->sc(mt((l+r)/2+1,r),1);
	re->ud();
	return re;
}
N *get(int l,int r)
{
	sct(l-1,O);
	sct(r+1,rt);
	return rt->R->L;
}
int ok(int x,int y,int l)
{
	return get(x,x+l-1)->h==get(y,y+l-1)->h;	
}
void init()
{
	O=mlc(0);
	O->sz=0;
	rt=mlc(0);
	rt->sc(mlc(0),1);
}
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int n,l,x,y,z;
	char o[9];
	g[0]=1;
	for(n=1;n<100020;n++)
		g[n]=g[n-1]*131;
	init();
	scanf("%s",s);
	for(l=0;s[l];l++)
		a[l+1]=s[l];
	rt->R->sc(mt(1,l),0);
	rt->R->spy(O);
	for(scanf("%d",&n);n--;)
	{
		scanf("%s",o);
		if(*o=='Q')
		{
			scanf("%d %d",&x,&y);
			z=0;
			for(int i=1<<18;i;i>>=1)
				if(x+i<=l+1&&y+i<=l+1&&ok(x,y,i))
					x+=i,y+=i,z+=i;
			printf("%d\n",z);
		}
		else if(*o=='R')
		{
			scanf("%d %s",&x,s);
			get(x,x)->set(*s);
			rt->R->spy(O);
		}
		else
		{
			scanf("%d %s",&x,s);
			l++;
			get(x+1,x);
			rt->R->sc(mlc(*s),0);
			rt->R->spy(O);
		}
	}
	return 0;
}
