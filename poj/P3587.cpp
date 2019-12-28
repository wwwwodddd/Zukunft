#include<stdio.h>
#include<math.h>
struct P
{
	double x,y;
	void scan()
	{
		scanf("%lf%lf",&x,&y);
	}
}p[720];
double z,d[720][720];
int n,t;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		z=0;
		for(int i=0;i<n;i++)
			p[i].scan();
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				d[i][j]=d[j][i]=hypot(p[i].x-p[j].x,p[i].y-p[j].y);
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				for(int k=j+1;k<n;k++)
				{
					double s=fabs((p[j].x-p[i].x)*(p[k].y-p[i].y)-(p[k].x-p[i].x)*(p[j].y-p[i].y));
					double r=d[i][j]*d[j][k]*d[k][i]/s*0.5;
					if(z<r)
						z=r;
				}
		printf("%.3f\n",z);
	}
	return 0;
}
