#include<stdio.h>
#include<math.h>
int main()
{
double s,h,r,v,pi=3.14159265358979323846;
while(scanf("%lf",&s)!=EOF)
{
h=sqrt(2*s/pi);
r=sqrt(s*s/(pi*pi*h*h+2*pi*s));
v=(1.0/3.0)*(s*s)*h/(pi*h*h+2*s);
printf("%.2lf\n%.2lf\n%.2lf\n",v,h,r);
}
return 0;
}