#include<stdio.h>
int t;
double x0,y0,x1,y1,x2,y2,a,b,c;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf%lf%lf%lf",&x0,&y0,&x1,&y1,&x2,&y2);
		a=(y1-y0)/((x1-x0)*(x1-x0));
		b=-2*a*x0;
		c=y0+a*x0*x0;
		printf("%.2f\n",a/3*(x2*x2*x2-x1*x1*x1)+b/2*(x2*x2-x1*x1)+c*(x2-x1)-(y2+y1)/2*(x2-x1));
	}
	return 0;
}
