#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
const double ml=100000;
const double eps=1e-8;
using namespace std;
struct P
{
	double x,y;
	P(double x=0,double y=0):x(x),y(y){}
}o;
int sgn(double x)
{
	return (x>eps)-(x<-eps);
}
double xm(P a,P b,P c)
{
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
struct V
{
	P s,e;double ag,d;
	V(){}
	V(P s,P e):s(s),e(e)
	{
		ag=atan2(e.y-s.y,e.x-s.x);
		if(sgn(s.x-e.x))
			d=xm(o,s,e)/fabs(s.x-e.x);
		else
			d=xm(o,s,e)/fabs(s.y-e.y);
	}
};
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
bool vcmp(const V l,const V r)
{
	if(sgn(l.ag-r.ag))
		return l.ag<r.ag;
	return l.d<r.d;
}
V dq[1520];
void hpc(V v[],int n,P p[],int &m)
{
	int i,tn;
	sort(v,v+n,vcmp);
	for(tn=i=1;i<n;i++)
		if(sgn(v[i].ag-v[i-1].ag)!=0)
			v[tn++]=v[i];
	n=tn;
	int b=0,f=1;
	dq[0]=v[0];
	dq[1]=v[1];
	for(i=2;i<tn;i++)
	{
		if(parallel(dq[f],dq[f-1]) || parallel(dq[b],dq[b+1]))
			return ;
		while(b<f && sgn(xm(v[i].s,v[i].e,cp(dq[f],dq[f-1])))<0)
			f--;
		while(b<f && sgn(xm(v[i].s,v[i].e,cp(dq[b],dq[b+1])))<0)
			b++;
		dq[++f]=v[i];
	}
	while(b<f&&sgn(xm(dq[b].s,dq[b].e,cp(dq[f],dq[f-1])))<0)
		f--;
	while(b<f&&sgn(xm(dq[f].s,dq[f].e,cp(dq[b],dq[b+1])))<0)
		b++;
	if(f<=b+1)
		return ;
	for(m=0,i=b;i<f;i++)
		p[m++]=cp(dq[i],dq[i+1]);
	if(b<f+1)
		p[m++]=cp(dq[b],dq[f]);
	m=unique(p,p+m,Equal)-p;
}
int n,m;
V v[1520];
P p[1520];
double S(P p[],int n)
{
	if(n<3)
		return 0;
	double s=p[0].y*(p[n-1].x-p[1].x);
	p[n]=p[0];
	for(int i=1;i<n;i++)
		s+=p[i].y*(p[i-1].x-p[(i+1)].x);
	return fabs(s/2);
}
void solve()
{
	int i,j;
	v[0]=V(P(-ml,-ml),P(ml,-ml));
	v[1]=V(P(ml,-ml),P(ml,ml));
	v[2]=V(P(ml,ml),P(-ml,ml));
	v[3]=V(P(-ml,ml),P(-ml,-ml));
	P a[1520];
	for(i=0;i<n;i++)
		scanf("%lf%lf",&a[i].x,&a[i].y);
	a[n]=a[0];
	for(j=4,i=n;i>0;i--)
		v[j++]=V(a[i],a[i-1]);
	n=j;
	hpc(v,n,p,m);
	printf("%.2lf\n",S(p,m));
}
int main()
{
	int csc;
	scanf("%d",&csc);
	while(csc--)
	{
		scanf("%d",&n);
		memset(p,0,sizeof(p));
		memset(v,0,sizeof(v));
		solve();
	}
	return 0;
}