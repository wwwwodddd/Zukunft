#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define eps 1e-8
#define pi acos(double(-1))
int ans,cnt,n;
struct P
{
	double x,y;
}p[305],z;
double D(P a,P b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
P C(P p1,P p2,double r)
{
	P u,v;
	double a,h,dx,dy;
	u.x=(p1.x+p2.x)/2;
	u.y=(p1.y+p2.y)/2;
	dx=p1.x-p2.x;
	dy=p1.y-p2.y;
	if(fabs(dy)<eps)
		a=pi/2;
	else
		a=atan(dx/dy);
	h=sqrt(r*r-D(u,p1)*D(u,p1));
	v.x=u.x+h*cos(a);
	v.y=u.y-h*sin(a);
	return v;
}
int main()
{
	int i,j,k;
	while(scanf("%d",&n)&&n)
	{
		ans=1;
		for(i=0;i<n;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				if(D(p[i],p[j])-2.0<eps)
				{
					cnt=0;
					z=C(p[i],p[j],1.0);
					for(k=0;k<n;k++)
						if(D(z,p[k])-1.0<eps)
							cnt++;
					if(cnt>ans)
						ans=cnt;
				}
		printf("%d\n",ans);
	}
	return 0;
}
