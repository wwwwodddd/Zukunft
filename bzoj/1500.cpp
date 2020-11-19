#include<stdio.h>
#include<iostream>
#define get(l,r) (sct(l-1,O),sct(r+1,rt),rt->R->L)
#define L a[0]
#define R a[1]
using namespace std;struct N *O,*rt,*s[1000020],**ss=s;
struct N{int l,r,m,s,w,z,v,e;N *a[2],*f;
	bool d(){return f->R==this;}void sc(N *y,int z){a[z]=y,y->f=this;}
	void set(int k){l=r=m=s=w=k,z=1,v=e=0,L=R=f=O;}
	void rev(){swap(L,R),swap(l,r),v^=1;}
	void sam(int u){if(this!=O)l=r=m=max(w=u,s=u*z),e=1;}
	void del(){if(this!=O)L->del(),*ss++=this,R->del();}
	void ud(){z=L->z+1+R->z,s=L->s+w+R->s;
		l=max(L->l,L->s+w+max(0,R->l));r=max(R->r,R->s+w+max(0,L->r));
		m=max(max(L->m,R->m),max(L->r,0)+w+max(R->l,0));}
	void pd(){if(v)L->rev(),R->rev(),v=0;if(e)L->sam(w),R->sam(w),e=0;}
	void rtt(){N *p=f;int c=d();p->sc(a[!c],c);p->f->sc(this,p->d());sc(p,!c);
		p->ud();if(p==rt)rt=this;}
	void spy(N *y){for(;f!=y;rtt())if(f->f!=y)d()==f->d()?f->rtt():rtt();ud();}
}t[1000020],*tt=t;int a[1000020],n,m,x,y,z;
N *mlc(int k){N *re=ss==s?tt++:*--ss;return re->set(k),re;}
void sct(int x,N *f){N *p=rt;for(;;){p->pd();int j=p->L->z;
	if(j==x)return p->spy(f);p=p->a[x>j];if(x>j)x-=j+1;}}
N *mt(int l,int r){if(l>r)return O;N *re=mlc(a[(l+r)/2]);
	re->sc(mt(l,(l+r)/2-1),0);re->sc(mt((l+r)/2+1,r),1);return re->ud(),re;}
int main(){char o[9];scanf("%d %d",&n,&m);for(int i=1;i<=n;i++)scanf("%d",a+i);
	O=mlc(-0xffffff),O->s=O->z=0,rt=mlc(-0xffffff),rt->sc(mlc(-0xffffff),1);
	rt->R->sc(mt(1,n),0);rt->R->spy(O);
	while(m--){scanf("%s",o);if(*o!='M'){scanf("%d %d",&x,&y);
			if(*o=='I'){for(int i=1;i<=y;i++)scanf("%d",a+i);
				get(x+1,x),rt->R->sc(mt(1,y),0),rt->R->spy(O);}
			if(*o=='D')get(x,x+y-1)->del(),rt->R->sc(O,0),rt->R->spy(O);
			if(*o=='R')get(x,x+y-1)->rev(),rt->R->spy(O);
			if(*o=='G')printf("%d\n",get(x,x+y-1)->s);}
		else if(o[2]=='X')printf("%d\n",rt->m);
		else scanf("%d %d %d",&x,&y,&z),get(x,x+y-1)->sam(z),rt->R->spy(O);}}
