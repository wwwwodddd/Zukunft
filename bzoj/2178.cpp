#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
double pi=acos(-1.);
double eps=1e-8;
struct P
{
	double r,x,y;
}p[10020],ps,pe,o;
struct seg
{
	double st,ed;
}l[20020];
int i,n,cnt;
double st,ed;
int sgn(double x)
{
	return (x>eps)-(x<-eps);
}
inline double dis(const P&a,const P&b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
inline double xm(P a,P b,P c)
{
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
inline void add(const double st,const double ed)
{
	if(ed>pi)
	{
		add(st,pi);
		add(-pi,ed-2*pi);
		return;
	}
	if(st<-pi)
	{
		add(st+2*pi,pi);
		add(-pi,ed);
		return;
	}
	l[cnt].st=st;
	l[cnt].ed=ed;
	cnt++;
	return;
}
bool cmp(const seg &a,const seg &b)
{
	if(sgn(a.st-b.st))
		return a.st<b.st;
	return a.ed<b.ed;
}
double F(double x)
{
	return x-sin(x);
}
int main()
{
	double ans=0;
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].r);
	for(i=0;i<n;i++)
	{
		cnt=0;
		double ag=0;
		for(j=0;j<n;j++)
			if(i!=j)
			{
				double r1,r2,dd;
				r1=p[i].r;
				r2=p[j].r;
				dd=dis(p[i],p[j]);
				if(sgn(dd+r1-r2)<=0)
					goto end;
				if(sgn(dd-r2-r1)>=0||sgn(dd-r1+r2)<=0)
					continue;
				double a=atan2(p[j].y-p[i].y,p[j].x-p[i].x);
				double b=acos((r1*r1+dd*dd-r2*r2)/(2*r1*dd));
				add(a-b,a+b);
			}
		sort(l,l+cnt,cmp);
		st=ed=-pi;
		for(j=0;j<cnt;j++)
		{
			if(l[j].st>ed)
			{
				st=l[j].st;
				ps.x=p[i].x+p[i].r*cos(st);
				ps.y=p[i].y+p[i].r*sin(st);
				pe.x=p[i].x+p[i].r*cos(ed);
				pe.y=p[i].y+p[i].r*sin(ed);
				ans+=xm(o,pe,ps)/2;
				ag+=F(st-ed);
				ed=l[j].ed;
			}
			else
				ed=max(ed,l[j].ed);
		}
		ps.x=p[i].x+p[i].r*cos(pi);
		ps.y=p[i].y+p[i].r*sin(pi);
		pe.x=p[i].x+p[i].r*cos(ed);
		pe.y=p[i].y+p[i].r*sin(ed);
		ans+=xm(o,pe,ps)/2;
		ag+=F(pi-ed);
		ans+=ag*p[i].r*p[i].r/2;
		end:;
	}
	printf("%0.3lf\n",ans+eps);
	return 0;
}