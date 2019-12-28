#include <cmath>  
#include <algorithm>  
#include <iostream>  
using namespace std;  
double eps=1e-8;
struct P{double x,y;P(double x=0,double y=0):x(x),y(y){}}s,u,r1,r2;
struct L{double s,e;}z[1020];
P operator+(P a,P b){return P(a.x+b.x,a.y+b.y);}
P operator-(P a,P b){return P(a.x-b.x,a.y-b.y);}
int sgn(double x){return (x>eps)-(x<eps);}
int cmp(L a,L b)
{
	if(sgn(a.s-b.s)==0)
		return a.e<b.e;
	return a.s<b.s;
}
int n;
double r;
P R(P a,double ag)
{
	return P(a.x*cos(ag)-a.y*sin(ag),a.x*sin(ag)+a.y*cos(ag));
}
void tg()
{
	double dis=sqrt((s.x-u.x)*(s.x-u.x)+(s.y-u.y)*(s.y-u.y));
	double ag=asin(r/dis);
	r1=R(u-s,ag)+s;
	r2=R(u-s,-ag)+s;
}
int main()
{
	while(scanf("%d",&n),n)
	{
		scanf("%lf%lf",&s.x,&s.y);
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf%lf",&u.x,&u.y,&r);
			tg();
			double x1=(s.x*r1.y-s.y*r1.x)/(r1.y-s.y);
			double x2=(s.x*r2.y-s.y*r2.x)/(r2.y-s.y);
			z[i].s=min(x1,x2);
			z[i].e=max(x1,x2);
		}
		sort(z,z+n,cmp);
		printf("%.2lf",z[0].s);
		double end=z[0].e;
		for(int i=1;i<n;i++)
		{
			if(sgn(z[i].s-end)>0)
				printf(" %.2lf\n%.2lf",end,z[i].s);
			end=max(end,z[i].e);
		}
		printf(" %.2lf\n\n",end);
	}
	return 0;
}