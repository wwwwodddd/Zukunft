#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<math.h>
#define eps 1e-8
using namespace std;
struct P
{
	double x,y;
	P(double x=0,double y=0):x(x),y(y){}
}p[50020],us[2020],ds[2020],st,ed;
double r[2020],u[2020],d[2020];
double t1,t2,t3,t4;
double ans;
int uss,dss,use,dse;
int s,n,l;
int sgn(double x)
{
	return (x>eps)-(x<-eps);
}
double xm(P a,P b,P c)
{
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
double dis(P a,P b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void ins(P up,P dp)
{
	while(uss>use&&sgn(xm(us[uss-1],us[uss],up))<0)
		uss--;
	us[++uss]=up;
	while(sgn(xm(us[use],us[uss],ds[dse+1]))>=0&&dss>dse)
	{
		ans+=dis(ds[dse],ds[dse+1]);
		dse++;
		us[use]=ds[dse];
	}
	while(dss>dse&&sgn(xm(ds[dss-1],ds[dss],dp))>0)
		dss--;
	ds[++dss]=dp;
	while(sgn(xm(ds[dse],ds[dss],us[use+1]))<=0&&uss>use)
	{
		ans+=dis(us[use],us[use+1]);
		use++;
		ds[dse]=us[use];
	}
	return;
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lf%lf%lf%lf",&t1,&t2,&t3,&t4);
		r[i-1]=t1;
		r[i]=t3;
		u[i-1]=min(u[i-1],t4);
		d[i-1]=max(d[i-1],t2);
		u[i]=t4;
		d[i]=t2;
	}
	scanf("%lf%lf",&st.x,&st.y);
	scanf("%lf%lf",&ed.x,&ed.y);
	if(st.x>ed.x)
		swap(st,ed);
	use=dse=1;
	us[++uss]=st;
	ds[++dss]=st;
	for(i=1;i<=n;i++)
		if(r[i]>st.x)
			break;
	for(;r[i]<=ed.x;i++)
		ins(P(r[i],u[i]),P(r[i],d[i]));
	ins(ed,ed);
	double V;
	scanf("%lf",&V);
	printf("%.10lf",ans/V);
	return 0;
}