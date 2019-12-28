#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
const double ml=100000;
const double eps=1e-8;
using namespace std;
struct P{double x,y;P(double x=0,double y=0):x(x),y(y){}};
int sgn(double x){return (x>eps)-(x<-eps);}
double xm(P a,P b,P c){return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);}
int intersect(P a,P b,P c,P d)
{return max(a.x,b.x)>=min(c.x,d.x)&&max(c.x,d.x)>=min(a.x,b.x)&&max(a.y,b.y)>=min(c.y,d.y)&&max(c.y,d.y)>=min(a.y,b.y)&&(sgn(xm(a,b,c))*sgn(xm(a,b,d)))<=0&&(sgn(xm(c,d,a))*sgn(xm(c,d,b)))<=0;}
struct V{P s,e;V(){}V(P s,P e):s(s),e(e){}}l1,l2;
bool Equal(P a,P b)
{
	return sgn(a.x-b.x)==0&&sgn(a.y-b.y)==0;
}
int parallel(V a,V b)
{
	return sgn((a.e.x-a.s.x)*(b.e.y-b.s.y)-(a.e.y-a.s.y)*(b.e.x-b.s.x))==0;
}
P cp(V a,V b)
{
	P re;
	double u=xm(a.s,a.e,b.s);
	double v=xm(a.e,a.s,b.e);
	re.x=(b.s.x*v+b.e.x*u)/(u+v);
	re.y=(b.s.y*v+b.e.y*u)/(u+v);
	return re;
}
int ud(P p,V l)
{
	if(sgn(l.s.x-l.e.x)==0)
		return 0;
	if(sgn(max(l.s.x,l.e.x)-p.x)<0||sgn(min(l.s.x,l.e.x)-p.x)>0)
		return 0;
	double h=(l.e.y*(p.x-l.s.x)+l.s.y*(l.e.x-p.x))/(l.e.x-l.s.x);
	return sgn(p.y-h)<0;
}
double work()
{
	if(!intersect(l1.s,l1.e,l2.s,l2.e))
		return 0;
	if(sgn((l1.e.x-l1.s.x)*(l2.e.y-l2.s.y)-(l2.e.x-l2.s.x)*(l1.e.y-l1.s.y))==0)
		return 0;
	if(sgn(l1.s.y-l1.e.y)==0||sgn(l2.s.y-l2.e.y)==0)
		return 0;
	P p=cp(l1,l2),c1,c2;
	V l;
	l.s.y=l.e.y=min(max(l1.s.y,l1.e.y),max(l2.s.y,l2.e.y));
	l.s.x=0;
	l.e.x=10000;
	c1=cp(l,l1);
	c2=cp(l,l2);
	if(ud(c1,l1)||ud(c2,l1)||ud(c1,l2)||ud(c1,l2))
		return 0;
	return fabs(xm(p,c1,c2)/2);
}
int main()
{
	int csc;
	freopen("data.txt","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&csc);
	while(csc--)
	{
		scanf("%lf%lf%lf%lf",&l1.s.x,&l1.s.y,&l1.e.x,&l1.e.y);
		scanf("%lf%lf%lf%lf",&l2.s.x,&l2.s.y,&l2.e.x,&l2.e.y);
		printf("%.2lf\n",work());
	}
	return 0;
}