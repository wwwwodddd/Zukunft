#include<stdio.h>
double xa,xb,xc,ya,yb,yc,a,b,c,s,x,y;
int main()
{
	while(~scanf("%lf%lf%lf%lf%lf%lf%*lf",&xa,&ya,&xb,&yb,&xc,&yc))
	{
		a=(xb-xc)*(xb-xc)+(yb-yc)*(yb-yc);
		b=(xc-xa)*(xc-xa)+(yc-ya)*(yc-ya);
		c=(xa-xb)*(xa-xb)+(ya-yb)*(ya-yb);
		s=a+b+c;
		x=(xa*a+xb*b+xc*c)/s;
		y=(ya*a+yb*b+yc*c)/s;
		printf("%.2f %.2f\n",x,y);
	}
}
