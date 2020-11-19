#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
const double inf=1e30;
const double eps=1e-8;
using namespace std;
struct P
{
	double x,y;
	P(double x=0,double y=0):x(x),y(y){}
}a[320],p[320],s[320],o;
int pc,sc,n;
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
double c1(double x)
{
	int i;
	for(i=1;i<n;i++)
		if(sgn(x-a[i].x)>=0&&sgn(x-a[i+1].x)<=0)
		{
			if(sgn(x-a[i].x)==0)
				return a[i].y;
			double k=(a[i+1].y-a[i].y)/(a[i+1].x-a[i].x);
			return a[i].y+k*(x-a[i].x);
		}
	return inf;
}
double c2(double x)
{
	int i;
	for(i=1;i<pc;i++)
		if(sgn(x-p[i].x)>=0&&sgn(x-p[i+1].x)<=0)
		{
			if(sgn(x-p[i].x)==0)
				return p[i].y;
			double k=(p[i+1].y-p[i].y)/(p[i+1].x-p[i].x);
			return p[i].y+k*(x-p[i].x);
		}
	return inf;
}
int main()
{
	int i;
	P u,v;
	double ans=inf;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%lf",&a[i].x);
	for(i=1;i<=n;i++)
		scanf("%lf",&a[i].y);
	p[1]=P(a[1].x,0);
	p[2]=P(a[n].x,0);
	p[3]=P(a[n].x,inf);
	p[4]=P(a[1].x,inf);
	p[pc=5]=p[1];
	for(i=1;i<n;i++)
		ins(a[i],a[i+1]);
	for(i=1;i<pc;i++)
		ans=min(ans,p[i].y-c1(p[i].x));
	for(i=1;i<=n;i++)
		ans=min(ans,c2(a[i].x)-a[i].y);
	printf("%.3lf\n",ans);
	return 0;
}