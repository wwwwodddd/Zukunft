#include<iostream>
#include<math.h>
using namespace std;
#define pi acos(-1.0)
double xa,ya,xb,yb,a,b;
double x,y,c,A,B,s,z,p;
int main()
{
	scanf("%lf%lf%lf%lf%lf%lf",&xa,&ya,&a,&xb,&yb,&b);
	double x=abs(xa-xb);
	double y=abs(ya-yb);
	double c=sqrt(x*x+y*y);
	if(c>=a+b)
		printf("0.000\n");
	else if(c<=abs(a-b))
		printf("%.3f\n",pi*min(a*a,b*b));
	else
	{
		A=acos((c*c+b*b-a*a)/(2*c*b));
		B=acos((c*c+a*a-b*b)/(2*c*a));
		p=(a+b+c)/2;
		s=sqrt(p*(p-a)*(p-b)*(p-c));
		z=a*a*B+b*b*A-2*s;
		printf("%.3f\n",z);
	}
	return 0;
}
