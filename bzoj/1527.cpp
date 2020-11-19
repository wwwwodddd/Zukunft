//DNF
#include<stdio.h>
#include<math.h>
#include<algorithm>
double eps=1e-6;
using namespace std;
int i,n,m;
int sgn(double x)
{
	return (x>eps)-(x<-eps);
}
double px[25020],py[25020];
double d[25020];
double z;
double H()
{
	double re=0,cx=0,cy=0;
	for(i=0;i<n;i++)
		cx+=px[i],cy+=py[i];
	cx/=n;
	cy/=n;
	for(i=0;i<n;i++)
		d[i]=sqrt((cx-px[i])*(cx-px[i])+(cy-py[i])*(cy-py[i]));
	sort(d,d+n);
	for(i=0;i<n-1;i++)
		d[i]/=d[n-1];
	for(i=0;i<n-1;i++)
		re+=sin(d[i]);
	return re;
}
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%lf%lf",&px[i],&py[i]);
	z=H();
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%lf%lf",&px[i],&py[i]);
		puts(sgn(H()-z)==0?"TAK":"NIE");
	}
	return 0;
}