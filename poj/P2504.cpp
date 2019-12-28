#include<algorithm>
#include<math.h>
#include<iostream>
using namespace std;
const double eps=1e-10,pi=acos(-1.0);
struct P{double x,y;}c;
double up,dn,lt,rt,r,d,a,x,y,xa,xb,xc,ya,yb,yc;
void cc()
{
	c.x=((yb-ya)*(yc*yc-ya*ya+xc*xc-xa*xa)-(yc-ya)*(yb*yb-ya*ya+xb*xb-xa*xa))/(2*(xc-xa)*(yb-ya)-2*((xb-xa)*(yc-ya)));
	c.y=((xb-xa)*(xc*xc-xa*xa+yc*yc-ya*ya)-(xc-xa)*(xb*xb-xa*xa+yb*yb-ya*ya))/(2*(yc-ya)*(xb-xa)-2*((yb-ya)*(xc-xa)));
}
int i,n,csc;
int main()
{
	while(scanf("%d",&n),n)
	{
		scanf("%lf%lf%lf%lf%lf%lf",&xa,&ya,&xb,&yb,&xc,&yc);
		cc();
		r=sqrt((c.x-xa)*(c.x-xa)+(c.y-ya)*(c.y-ya));
		d=2*pi/n;
		a=acos((xa-c.x)/r);
		if(ya<c.y)
			a=2*pi-a;
		a+=d;
		lt=rt=xa;
		dn=up=ya;
		for(i=1;i<n;i++,a+=d)
		{
			x=c.x+r*cos(a);
			y=c.y+r*sin(a);
			lt=min(lt,x);
			rt=max(rt,x);
			dn=min(dn,y);
			up=max(up,y);
		}
		printf("Polygon %d: %.3lf\n",++csc,(rt-lt)*(up-dn));
	}
	return 0;
}