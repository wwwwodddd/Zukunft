#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
double a,b,c,d,e,f;
double sqr(double x)
{
	return x*x;
}
int main()
{
	while(scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f)+1)
		printf("%.4lf\n",sqrt(4*a*a*b*b*c*c-a*a*sqr(b*b+c*c-f*f)-b*b*sqr(a*a+c*c-e*e)-c*c*sqr(a*a+b*b-d*d)+(a*a+b*b-d*d)*(a*a+c*c-e*e)*(b*b+c*c-f*f))/12);
	return 0;
}