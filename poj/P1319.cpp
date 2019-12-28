#include<iostream>
#include<math.h>
using namespace std;
double eps=1E-8;
int sgn(double x)
{
	return (x>eps)-(x<-eps);
}
int cal(double A,double B)
{
	int a=(int)A,re=0,h;
	double sq3=sqrt(3.0);
	double lft=A-floor(A);
	if(sgn(1.0-B)>0)
		return 0;
	re+=a;
	B-=1.0;
	h=int(2.0*B/sq3);
	if(sgn(lft-0.5)>=0)
		re += a*h;
	else
	{
		if(h&1)
			re+=(h/2*a)+((h/2+1)*(a-1));
		else
			re+=h/2*(2*a-1);
	}
	return re;
}
int main()
{
	double A,B;
	int z,v;
	while(scanf("%lf %lf",&A,&B)+1)
	{
		v=0;
		z=max(cal(A,B),cal(B,A));
		if((int)(A+eps)*(int)(B+eps)>=z)
			z=(int)(A+eps)*(int)(B+eps),v=1;
		printf("%d %s\n",z,v?"grid":"skew");
	}
	return 0;
}