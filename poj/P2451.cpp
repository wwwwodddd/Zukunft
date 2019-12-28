#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
const double inf=1e8;
const double eps=1e-8;
using namespace std;
struct P
{
	double x,y;
	P(double x=0,double y=0):x(x),y(y){}
}a[205],p[205],s[205],o;
int pc,sc;
double r;
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
void ins(P a,P b)
{
	int i;
	sc=0;
	for(i=1;i<pc;i++)
	{
		if(sgn(xm(a,b,p[i]))>=0)
			s[++sc]=p[i];
		if(sgn(xm(a,b,p[i])*xm(a,b,p[i+1]))<0)
			s[++sc]=cp(a,b,p[i],p[i+1]);
	}
	pc=sc;
	if(sc==0)
		return;
	memcpy(p,s,sizeof(p));
	p[++pc]=p[1];
	return;
}
void mov(P a,P b,P&c,P&d)
{
	P o=P(a.y-b.y,b.x-a.x);
	double l=sqrt(o.x*o.x+o.y*o.y);
	o.x=o.x/l*r;
	o.y=o.y/l*r;
	c.x=a.x+o.x;
	c.y=a.y+o.y;
	d.x=b.x+o.x;
	d.y=b.y+o.y;
	return;
}
double dis(P a,P b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
double S(P p[],int n)
{
	double re=0;
	int i;
	for(i=1;i<n;i++)
		re+=xm(o,p[i],p[i+1]);
	return fabs(re/2);
}
int main()
{
	int n,i,j,ans1,ans2;
	P u,v;
	double ans=0,ds;
	scanf("%d",&n);
	p[1]=P(0,0);
	p[2]=P(10000,0);
	p[3]=P(10000,10000);
	p[4]=P(0,10000);
	p[pc=5]=p[1];
	for(i=1;i<=n;i++)
	{
		scanf("%lf%lf%lf%lf",&u.x,&u.y,&v.x,&v.y);
		ins(u,v);
	}
	printf("%.1lf\n",S(p,pc));
	return 0;
}