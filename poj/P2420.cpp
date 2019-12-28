#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define tms 100
#define RD 1000
#define eps 0.01
#define dd 0.7
int n;
struct P
{
	double x,y,w;
	P(){}
	P(double x,double y):x(x),y(y){}
}p[200],z;
double dist(P a,P b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double calc(P id)
{
	double sum=0;
	for(int i=0;i<n;i++)
		sum+=dist(id,p[i]);
	return sum;
}
double rd()
{
	return (rand()%(RD+1))*1.0/RD;
}
P RP(P a,P b)
{
	P re=P(a.x+(b.x-a.x)*rd(),a.y+(b.y-a.y)*rd());
	re.w=calc(re);
	return re;
}
void sv(double dz)
{
	for(;dz>eps;dz*=dd)
		for(int j=0;j<tms;j++)
			{
				P u=RP(P(z.x-dz,z.y-dz),P(z.x+dz,z.y+dz));
				if(z.w>u.w)
					z=u;
			}
}
int main()
{
	while(scanf("%d",&n)+1)
	{
		P tr=P(100000.0,100000.0),ul=P(-100000.0,-100000.0);
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf", &p[i].x, &p[i].y);
			tr.x=min(tr.x,p[i].x);
			tr.y=min(tr.y,p[i].y);
			ul.x=max(ul.x,p[i].x);
			ul.y=max(ul.y,p[i].y);
		}
		z=P((tr.x+ul.x)/2,(tr.y+ul.y)/2);
		z.w=calc(z);
		sv(max(ul.y-tr.y,ul.x-tr.x));
		printf("%.0f\n",z.w);
	}
	return 0;
}