#include<iostream>
using namespace std;
struct point{double x,y;}a,b,c,z;
double a1,b1,a2,b2,c1,c2;
int t;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;  
		a1=c.x-b.x;
		b1=c.y-b.y;
		c1=0;
		a2=c.x-a.x;
		b2=c.y-a.y;
		c2=(b.x-a.x)*a2+(b.y-a.y)*b2;
		z.x=a.x+(c1*b2-c2*b1)/(a1*b2-a2*b1);
		z.y=a.y+(a1*c2-a2*c1)/(a1*b2-a2*b1);
		printf("%.4lf %.4lf\n",z.x,z.y);
	}
	return 0;
}