#include<iostream>
#include<math.h>
using namespace std;
#define pi 3.1415926
double h,k,x[105],y[105],mx,mn,sum;
double Angle(double x1,double y1,double x2,double y2)
{
	double a1=atan2(y1,x1),a2=atan2(y2,x2);
	if(a2-a1>pi)
		a1+=2*pi;
	if(a1-a2>pi)
		a2+=2*pi;
	return a1-a2;
}
int main()
{
	int n,i;
	scanf("%lf%lf%d",&k,&h,&n);
	for(i=0;i<n;i++)
		scanf("%lf%lf",&x[i],&y[i]);
	x[n]=x[0],y[n]=y[0];
	for(i=0;i<n;i++)
	{
		sum+=Angle(x[i],y[i],x[i+1],y[i+1]);
		mn=min(mn,sum);
		mx=max(mx,sum);
		if(mx-mn>=2*pi)
		{
			mx=mn+2*pi;
			break;
		}
	}
	printf("%.2lf\n",(mx-mn)*k*h);
	return 0;
}