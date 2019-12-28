#include<iostream>
#include<math.h>
#define pi acos(-1.0)
using namespace std;
int i;
double x[4],y[4],p,q,ans,c1,c2,u,l,t,a,b;
int main()
{
	while(scanf("%lf%lf%lf",&t,&a,&b),t)
	{
		for(i=0;i<3;i++)
			scanf("%lf%lf",&x[i],&y[i]);
		a=a/t*2*pi;
		p=x[0];
		q=y[0];
		x[0]=p*cos(a)-q*sin(a);
		y[0]=p*sin(a)+q*cos(a);
		b=-b/t*2*pi;
		p=x[2];
		q=y[2];
		x[2]=p*cos(b)-q*sin(b);
		y[2]=p*sin(b)+q*cos(b);
		c1=(x[0]*x[0]+y[0]*y[0]-x[1]*x[1]-y[1]*y[1])/2;
		c2=(x[0]*x[0]+y[0]*y[0]-x[2]*x[2]-y[2]*y[2])/2;
		p=(c1*(y[0]-y[2])-c2*(y[0]-y[1]))/((x[0]-x[1])*(y[0]-y[2])-(x[0]-x[2])*(y[0]-y[1]));
		q=(c1*(x[0]-x[2])-c2*(x[0]-x[1]))/((y[0]-y[1])*(x[0]-x[2])-(y[0]-y[2])*(x[0]-x[1]));
		printf("%.0lf\n",sqrt(p*p+q*q));
	}
	return 0;
}