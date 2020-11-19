#include<stdio.h>
#include<math.h>
int t;
double xa,ya,xb,yb,ag,pi=acos(-1.);
int main()
{
    for(scanf("%d",&t);t--;)
    {
        scanf("%lf%lf%lf%lf",&xa,&ya,&xb,&yb);
        ag=atan2(ya,xa)-atan2(yb,xb);
        ag=fabs(ag);
        if(ag>pi)
            ag=2*pi-ag;
        printf("%.2f\n",ag/pi*180);
    }
}
