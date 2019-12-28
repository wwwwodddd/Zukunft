#include<iostream>
#include<stdio.h>
#define EPS 1e-8
using namespace std;
double dis(int a,int s,int d,int f)
{
return sqrt((double)(d-a)*(d-a)+(f-s)*(f-s));
}
double min(double x,double y)
{
return x<y?x:y;
}
double max(double x,double y)
{
return x>y?x:y;
}
int main()
{
int x1,y1,x2,y2,x3,y3;
double a,b,c,p,s,r,x;
scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
a=dis(x1,y1,x2,y2);
b=dis(x2,y2,x3,y3);
c=dis(x3,y3,x1,y1);
p=(a+b+c)/2;
s=sqrt(p*(p-a)*(p-b)*(p-c));
r=a*b*c/4/s;
s*=2;
r=4000020;
r=min(max(s/a,a)*max(s/a,a),r);
r=min(max(s/b,b)*max(s/b,b),r);
r=min(max(s/c,c)*max(s/c,c),r);
r/=2;
if(r-floor(r)<EPS)
	printf("%.0lf",floor(r));
else
	printf("%.0lf",ceil(r));
return 0;
}