#include<stdio.h>
#include<math.h>
struct P{double x,y,z;P(double x=0,double y=0,double z=0):x(x),y(y),z(z){}}p[10];
int i;
double ans;
P operator -(const P&a,const P&b)
{
	return P(a.x-b.x,a.y-b.y,a.z-b.z);
}
P xm(P a,P b)
{
	return P(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);
}
double dm(P a,P b)
{
	return a.x*b.x+a.y*b.y+a.z*b.z;
}
double V(P a,P b,P c,P d)
{
	b=b-a;
	c=c-a;
	d=d-a;
	return fabs(dm(b,xm(c,d)))/6;
}
int main()
{
	for(i=0;i<5;i++)
		scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].z);
	ans+=V(p[0],p[1],p[2],p[3]);
	ans+=V(p[0],p[1],p[2],p[4]);
	ans+=V(p[0],p[1],p[3],p[4]);
	ans+=V(p[0],p[2],p[3],p[4]);
	ans+=V(p[1],p[2],p[3],p[4]);
	printf("%.2lf",ans/2);
	return 0;
}