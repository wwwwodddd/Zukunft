#include<iostream>
#include<cmath>
using namespace std;
#define inf 1e20
#define eps 1e-6
#define N 120
struct P
{
	double x,y,z;
}ps[N],q;
int n;
double dist(P a,P b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}
int md(P p)
{
	double res=0;
	int k=0,i;
	for(i=0;i<n;i++)
	{
		double tmp=dist(p,ps[i]);
		if(tmp>res)
		{
			k=i;
			res=dist(p,ps[i]);
		}
	}
	return k;
}
int main()
{
	while(scanf("%d",&n),n)
	{
		int i;
		for(i=0;i<n;i++)
			scanf("%lf%lf%lf",&ps[i].x,&ps[i].y,&ps[i].z);
		double step=100;
		double ans=inf;
		q.x=q.y=q.z=0;
		int k=1;
		while(step>eps)
		{
			int d=md(q);
			double tmp=dist(ps[d],q);
			if(ans>tmp)
				ans=tmp;
			double dx=ps[d].x-q.x;
			double dy=ps[d].y-q.y;
			double dz=ps[d].z-q.z;
			dx=dx/tmp;
			dy=dy/tmp;
			dz=dz/tmp;
			q.x+=dx*step;
			q.y+=dy*step;
			q.z+=dz*step;
			step*=0.99;
		}
		printf("%.5lf\n",ans);
	}
	return 0;
}