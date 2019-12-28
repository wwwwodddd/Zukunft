#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;
#define eps 1e-8
struct P{double x,y;P(){}P(double x,double y):x(x),y(y){}}p[30];
int n,o;
double ans;
double intersect(P a1, P b1, P a2, P b2)
{
	double x1=a1.x,x2=b1.x,x3=a2.x,x4=b2.x;
	double y1=a1.y,y2=b1.y,y3=a2.y,y4=b2.y;
	return (y3-y1+x1*(y2-y1)/(x2-x1)-x3*(y4-y3)/(x4-x3))/((y2-y1)/(x2-x1)-(y4-y3)/(x4-x3));
}
void work(P a, P b)
{
	b.y-=1;
	int i;
	for(i=0;i<n;i++)
	{
		P u,l,r;
		u.x=p[i].x;
		u.y=a.y-(b.y-a.y)/(b.x-a.x)*(a.x-u.x);
		if((u.y+eps<p[i].y&&u.y-eps>p[i].y-1)||abs(u.y- p[i].y)<eps||abs(u.y-p[i].y+1)<eps)
			continue;
		if(i==0)
			return;
		if(u.y-eps>p[i].y)
			ans=max(ans,intersect(a,b,p[i-1],p[i]));
		else
			ans=max(ans,intersect(a,b,P(p[i-1].x,p[i-1].y-1),P(p[i].x,p[i].y-1)));
		return;
	}
	o=1;
}
int main()
{
	int i,j;
	while(scanf("%d", &n),n)
	{
		for(i=0;i<n;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		ans= p[0].x;
		o=0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(i!=j&&!o)
					work(p[i],p[j]);
		if(o)
			printf("Through all the pipe.\n");
		else
			printf("%.2f\n",ans);
	}
	return 0;
}