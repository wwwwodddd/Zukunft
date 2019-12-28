#include<iostream>
#include<math.h>
using namespace std;
const double pi=3.1415926535;
int t,i,k;
double m,n,l,d;
double s,p1,p2,p3,p4;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf %lf %lf %lf",&m,&n,&l,&d);
		s=m*n*l*l;
		p2=(m-1)*n*l*d+(n-1)*m*l*d-2*(m-1)*(n-1)*d*d;
		p3=(m-1)*(n-1)*d*d*(1-pi/4);
		p4=(m-1)*(n-1)*d*d*pi/4;
		p1=s-(p2+p3+p4);
		printf("Case %d:\n",++k);
		printf("Probability of covering 1 tile  = %.4lf%c\n",p1/s*100,'%');
		printf("Probability of covering 2 tiles = %.4lf%c\n",p2/s*100,'%');
		printf("Probability of covering 3 tiles = %.4lf%c\n",p3/s*100,'%');
		printf("Probability of covering 4 tiles = %.4lf%c\n",p4/s*100,'%');
		printf("\n");
	}
	return 0;
}
