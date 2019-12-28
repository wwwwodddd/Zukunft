#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
double eps=1e-8;
struct P
{
	double x,y;
	P(double x=0,double y=0):x(x),y(y){}
};
int sgn(double x)
{
	return (x>eps)-(x<-eps);
}
double xm(P a,P b,P c)
{
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
P cp(P as,P ae,P bs,P be)
{
	P re;
	double u=xm(as,ae,bs);
	double v=xm(ae,as,be);
	re.x=(bs.x*v+be.x*u)/(u+v);
	re.y=(bs.y*v+be.y*u)/(u+v);
	return re;
}
double dis(P a,P b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
P cc(P a,P b,P c)
{
	P ua,va,ub,vb;
	ua=P((a.x+b.x)/2,(a.y+b.y)/2);
	ub=P(ua.x-a.y+b.y,ua.y+a.x-b.x);
	va=P((a.x+c.x)/2,(a.y+c.y)/2);
	vb=P(va.x-a.y+c.y,va.y+a.x-c.x);
	return cp(ua,ub,va,vb);
}
int main()
{
	P a,b,c,p;
	double r,t;
	while(scanf("%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y)+1)
	{
		p=cc(a,b,c);
		r=dis(p,a);
		t=p.x*p.x+p.y*p.y-r*r;
		if(p.x>0)
			printf("(x - %.3lf)^2",p.x);
		else
			printf("(x + %.3lf)^2",-p.x);
		if(p.y>0)
			printf(" + (y - %.3lf)^2 = %.3lf^2\n",p.y,r);
		else
			printf(" + (y + %.3lf)^2 = %.3lf^2\n",-p.y,r);
		if(p.x>0)
			printf("x^2 + y^2 - %.3lfx",2*p.x);
		else
			printf("x^2 + y^2 + %.3lfx",-2*p.x);
		if(p.y>0)
			printf(" - %.3lfy",p.y*2);
		else
			printf(" + %.3lfy",-2*p.y);
		if(t>0)
			printf(" + %.3lf = 0\n",t);
		else
			printf(" - %.3lf = 0\n",-t);
		printf("\n");
	}
	return 0;
}