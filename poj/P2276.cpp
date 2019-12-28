#include<iostream>
#include<math.h>
using namespace std;
double D,H,a,b,y;
int main()
{
	cin>>D>>H;
	while (cin>>a>>b>>y,a+b+y>0)
	{
		a=a/180*3.1415926535;
		b=b/180*3.1415926535;
		y=y/180*3.1415926535;
		printf("%.0lf\n", H+sqrt(2*D*D*tan(b)*tan(b)/(1/tan(y)*tan(b)*tan(b)*1/tan(y)+1/tan(a)*tan(b)*tan(b)*1/tan(a)-2)));
	}
	return 0;
}
