#include<stdio.h>
double a[8][2];
double s,d,f;
int i,j,k;
double abs(double x)
{
	return x>0?x:-x;
}
double cp(double x0,double x1,double y0,double y1)
{
	return abs(x0*y1-x1*y0)/2;
}
double S(double *x,double *y,double *z)
{
	return cp(x[0]-z[0],x[1]-z[1],y[0]-z[0],y[1]-z[1]);
}
void check(int q,int w,int e)
{
	f=S(a[q],a[w],a[e]);
	if(abs(s-f-f)<d)
		d=abs(s-f-f);
	return;
}
int main()
{
	while(1)
	{
		for(i=0;i<4;i++)
			scanf("%lf %lf",&a[i][0],&a[i][1]);
		for(i=0;i<4;i++)
			if(a[i][0]||a[i][1])
				goto c;
		break;
		c:
		a[4][0]=a[0][0];
		a[4][1]=a[0][1];
		for(i=7;i>3;i--)
		{
			a[i][0]=(a[i-4][0]+a[i-3][0])/2;
			a[i][1]=(a[i-4][1]+a[i-3][1])/2;
		}
		s=S(a[0],a[1],a[2])+S(a[0],a[2],a[3]);
		d=s;
		check(0,1,2);
		check(1,2,3);
	
		check(0,1,5);
		check(0,1,7);
		check(1,2,6);
		check(1,2,4);
		check(2,3,7);
		check(2,3,5);
		check(3,0,4);
		check(3,0,6);

		check(0,4,7);
		check(1,5,4);
		check(2,6,5);
		check(3,7,6);

		f=S(a[1],a[6],a[4])+S(a[1],a[6],a[2]);
		if(abs(s-f-f)<d)
			d=abs(s-f-f);
		f=S(a[0],a[5],a[1])+S(a[0],a[5],a[7]);
		if(abs(s-f-f)<d)
			d=abs(s-f-f);
		printf("Cake %d: %.3lf %.3lf\n",++k,(s-d)/2,(s+d)/2);
	}
	return 0;
}