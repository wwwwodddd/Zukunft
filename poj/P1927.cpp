#include<iostream>
#include<math.h>
using namespace std;
const double pi=acos(-1.0);
double x,y,z,l,p,v,R,r,c,s;
int t;
int main()
{
	while(scanf("%lf%lf%lf%lf",&x,&y,&z,&l),x+y+z+l)
	{
		c=(x+y+z);
		p=c/2;
		s=sqrt(p*(p-x)*(p-y)*(p-z));
		R=s*2.0/c;
		if(x+y+z<=l)
			v=s;
		else if(2.0*pi*R>=l)
			v=l*l/(4.0*pi);
		else
		{
			r=(c-l)/(c/R-2.0*pi);
			v=s+pi*r*r-(r*r*s/(R*R));
		}
		printf("Case %d: %.2lf\n",++t,v);
	}
	return 0;
}