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
int pc,sc,flag;
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
double S(P p[],int n)
{
	double re=0;
	int i;
	for(i=1;i<n;i++)
		re+=xm(o,p[i],p[i+1]);
	return fabs(re/2);
}
double dis(P a,P b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
char od[10];
int main()
{
	P u,v,s,e;
	p[1]=P(0,0);
	p[2]=P(10,0);
	p[3]=P(10,10);
	p[4]=P(0,10);
	p[pc=5]=p[1];
	while(scanf("%lf%lf%s",&e.x,&e.y,od)+1)
	{
		if(od[0]=='S'||flag)
		{
			printf("0.00\n");
			flag=1;
			continue;
		}
		u=P((e.x+s.x)/2,(e.y+s.y)/2);
		v=P(s.y-e.y+u.x,e.x-s.x+u.y);
		if(od[0]=='C')
			ins(u,v);
		else
			ins(v,u);
		printf("%.2lf\n",S(p,pc));
		s=e;
	}
	return 0;
}