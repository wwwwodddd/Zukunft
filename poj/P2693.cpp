#include<stdio.h>
#include<math.h>
#define eps 1e-8
int ans,cnt,n;
int i,j,k;
struct P{double x,y;}p[305],z;
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
		a=acos(-1.0)/2;
	else
		a=atan(dx/dy);
	h=sqrt(r*r-D(u,p1)*D(u,p1));
	v.x=u.x+h*cos(a);
	v.y=u.y-h*sin(a);
	return v;
}
int main()
{
	while(scanf("%lf%lf",&p[i].x,&p[i].y)+1)
		i++;
	n=i;
	ans=1;
	for(i=3;i<n;i++)
		for(j=6;j<n;j++)
			if(D(p[i],p[j])-5.0<eps)
			{
				cnt=0;
				z=C(p[i],p[j],2.5);
				for(k=0;k<n;k++)
					if(D(z,p[k])-2.5<eps)
						cnt++;
				if(cnt>ans)
					ans=cnt;
			}
	printf("%d\n",ans);
	return 0;
}
