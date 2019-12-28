#include<algorithm>
#include<iostream>
#include<math.h>
using namespace std;
double eps=1e-6;
struct P{double x,y;P(double x=0,double y=0):x(x),y(y){}}p1[10020],p2[10020],o;
int sgn(double x){return (x>eps)-(x<-eps);}
double xm(P a,P b,P c){return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);}
double dm(P a,P b){return a.x*b.x+a.y*b.y;}
double dis(P a,P b){return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}
int ss,i,n1,n2;
double pl(P c,P a,P b)
{
	P ab=P(b.x-a.x,b.y-a.y);
	P ac=P(c.x-a.x,c.y-a.y);
	double f=dm(ab,ac);
	if(f<0)
		return dis(a,c);
	double D=dm(ab,ab);
	if(f>D)
		return dis(b,c);
	f=f/D;
	P d=P(a.x+f*ab.x,a.y+f*ab.y);
	return dis(d,c);
}
double apl(P p1, P p2, P p3, P p4)
{
	return min(min(pl(p1,p3,p4),pl(p2,p3,p4)),min(pl(p3,p1,p2),pl(p4,p1,p2)));
}
double RC(P s1[],int l1,P s2[],int l2)
{
	double ans=1E30,dd;
	int q=0,p=0;
	for(int i=0;i<l1;i++) 
		if(sgn(s1[i].y-s1[p].y)<0)
			p=i;
	for(int i=0;i<l2;i++)
		if(sgn(s2[i].y-s2[q].y)>0)
			q=i;
	s1[l1]=s1[0];
	s2[l2]=s2[0];
	for(int i=0;i<l1;i++)
	{
		while(sgn(dd=xm(s1[p+1],s2[q+1],s1[p])-xm(s1[p+1],s2[q],s1[p]))>0)
			q=(q+1)%l2;
		if(sgn(dd)<0)
			ans=min(ans,pl(s2[q],s1[p],s1[p+1]));
		else
			ans=min(ans,apl(s1[p],s1[p+1],s2[q],s2[q+1]));
		p=(p+1)%l1;
	}
	return ans;
}
double S(P p[],int n)
{
	double re=0;
	int i;
	for(i=1;i<n;i++)
		re+=xm(o,p[i],p[i+1]);
	return re/2;
}
int main()
{
	while(scanf("%d %d",&n1,&n2),n1+n2)
	{
		for(i=0;i<n1;i++)
			scanf("%lf %lf",&p1[i].x,&p1[i].y);
		for(i=0;i<n2;i++)
			scanf("%lf %lf",&p2[i].x,&p2[i].y);
		if(S(p1,n1)<0)
			reverse(p1,p1+n1);
		if(S(p2,n2)<0)
			reverse(p2,p2+n2);
		printf("%.5lf\n",sqrt(min(RC(p1,n1,p2,n2),RC(p2,n2,p1,n1))));
	}
	return 0;
}