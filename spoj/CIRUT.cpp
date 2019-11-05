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
	double ag;
	int d;
}l[20020];
int i,n,cnt,cc;
double ans[1020];
double st,ed;
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
	l[cnt].ag=st;
	l[cnt].d=1;
	cnt++;
	l[cnt].ag=ed;
	l[cnt].d=-1;
	cnt++;
	return;
}
bool cmp(const seg &a,const seg &b)
{
	return a.ag<b.ag;
}
double F(double x)
{
	return x-sin(x);
}
int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].r);
	for(i=0;i<n;i++)
	{
		cnt=0;
		double ag=0;
		add(-pi,pi);
		for(j=0;j<n;j++)
			if(i!=j)
			{
				double r1,r2,dd;
				r1=p[i].r;
				r2=p[j].r;
				dd=dis(p[i],p[j]);
				if(dd+r1-r2<=0)
				{
					add(-pi,pi);
					continue;
				}
				if(dd-r2-r1>=0||dd-r1+r2<=0)
					continue;
				double a=atan2(p[j].y-p[i].y,p[j].x-p[i].x);
				double b=acos((r1*r1+dd*dd-r2*r2)/(2*r1*dd));
				add(a-b,a+b);
			}
		sort(l,l+cnt,cmp);
		cc=1;
		for(j=1;j<cnt;j++)
		{
			st=l[j-1].ag;
			ed=l[j].ag;
			ps.x=p[i].x+p[i].r*cos(ed);
			ps.y=p[i].y+p[i].r*sin(ed);
			pe.x=p[i].x+p[i].r*cos(st);
			pe.y=p[i].y+p[i].r*sin(st);
			ans[cc]+=xm(o,pe,ps)/2;
			ans[cc]+=F(ed-st)*p[i].r*p[i].r/2;
			cc+=l[j].d;
		}
	}
	for(i=1;i<=n;i++)
		printf("[%d] = %.3lf\n",i,ans[i]-ans[i+1]);
	return 0;
}