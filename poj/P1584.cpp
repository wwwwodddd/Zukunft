#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
#define eps 1E-8
struct P{double x,y;P(double x=0,double y=0):x(x),y(y){}}p[2000],o;
int sgn(double x){return (x>eps)-(x<-eps);}
double xm(P a,P b,P c){return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);}
double dis(P a,P b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
double r;
int t,i,j,k,n;
int main()
{
	while(cin>>n,n>2)
	{
		cin>>r>>o.x>>o.y;
		for(i=0;i<n;i++)
			cin>>p[i].x>>p[i].y;
		for(i=t=0;i<n&&t==0;i++)
			t=sgn(xm(p[i],p[(i+1)%n],p[(i+2)%n]));
		if(t<0)
			reverse(p,p+n);
		for(i=0;i<n;i++)
			if(sgn(xm(p[(i+1)%n],p[i],p[(i+2)%n]))>0)
				break;
		if(i!=n)
			puts("HOLE IS ILL-FORMED");
		else
		{
			for(i=0;i<n;i++)
				if(sgn(xm(o,p[i],p[(i+1)%n])/dis(p[i],p[(i+1)%n])-r)<0)
					break;
			printf("PEG WILL %sFIT\n",i!=n?"NOT ":"");
		}
	}
	return 0;
}