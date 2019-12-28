#include<iostream>
#define p 3.141592653589793
using namespace std;
double w,h;
int main()
{
	while(scanf("%lf%lf",&w,&h)&&w+h)
		printf("%.3lf\n",max(w*w*(h*p-w)/(4*p*p),p*w/4*min(h/(p+1),w)*min(h/(p+1),w)));
}
