#include<stdio.h>
#include<math.h>
struct P
{
	double x,y,z,l;
	void scan()
	{
		scanf("%lf %lf %lf",&x,&y,&z);
		l=sqrt(x*x+y*y+z*z);
	}
	double dot(const P&a)const
	{
		return x*a.x+y*a.y+z*a.z;
	}
}p[1020],q[1020];
double a[1020];
int n,m,z;
int main()
{
	while(scanf("%d",&n),n)
	{
		for(int i=z=0;i<n;i++)
			p[i].scan();
		scanf("%d",&m);
		for(int i=0;i<m;i++)
			q[i].scan(),scanf("%lf",a+i),a[i]=cos(a[i]);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(p[i].dot(q[j])>a[j]*p[i].l*q[j].l)
				{
					z++;
					break;
				}
		printf("%d\n",z);
	}
}
