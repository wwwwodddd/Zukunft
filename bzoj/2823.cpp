#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;
const double eps=1e-12;
struct P{double x,y;}q[1000010],p;
int i,j,k,n;
double r;
double dis(P a, P b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void cal(int i,int j,int k)
{
	double a1,a2,b1,b2,c1,c2;
	a1=2*(q[i].x-q[j].x);
	b1=2*(q[i].y-q[j].y);
	c1=q[i].x*q[i].x-q[j].x*q[j].x+q[i].y*q[i].y-q[j].y*q[j].y;
	a2=2*(q[i].x-q[k].x);
	b2=2*(q[i].y-q[k].y);
	c2=q[i].x*q[i].x-q[k].x*q[k].x+q[i].y*q[i].y-q[k].y*q[k].y;
	p.x=(c1*b2-c2*b1)/(a1*b2-a2*b1);
	p.y=(c1*a2-c2*a1)/(b1*a2-b2*a1);
	r=dis(p,q[k]);
}
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%lf%lf",&q[i].x,&q[i].y);
	random_shuffle(q,q+n);
	r=0,p=q[0];
	for(i=1;i<n;i++)
		if(dis(p,q[i])>r-eps)
		{
			p.x=(q[0].x+q[i].x)/2;
			p.y=(q[0].y+q[i].y)/2;
			r=dis(p,q[i]);
			for(j=0;j<i;j++)
				if(dis(p,q[j])>r-eps)
				{
					p.x=(q[i].x+q[j].x)/2;
					p.y=(q[i].y+q[j].y)/2;
					r=dis(p,q[j]);
					for(k=0;k<j;k++)
						if(dis(p,q[k])>r-eps)
							cal(i,j,k);
				}
		}
	printf("%.2f %.2f %.2f\n",p.x,p.y,r+eps);
	return 0;
}
