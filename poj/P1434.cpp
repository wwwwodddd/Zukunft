#include<iostream>
using namespace std;
struct R{double b,h,w,d;}a[50020];
double eps=1e-8;
int i,csc,n;
double l,r,s,v,mid;
int sgn(double x)
{
	return (x>eps)-(x<-eps);
}
int check(double x)
{
	s=0;
	for(i=0;i<n;i++)
		if(x>a[i].b)
			s+=a[i].w*a[i].d*min(x-a[i].b,a[i].h);
	return s<v;
}
double work()
{
	while(r-l>1e-6)
	{
		mid=(l+r)/2;
		if(check(mid))
			l=mid;
		else
			r=mid;
	}
	return r;
}
int main()
{
	scanf("%d",&csc);
	while(csc--)
	{
		s=l=r=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf%lf%lf",&a[i].b,&a[i].h,&a[i].w,&a[i].d);
			s+=a[i].h*a[i].w*a[i].d;
			r=max(r,a[i].b+a[i].h);
		}
		scanf("%lf",&v);
		if(v>s)
		{
			printf("OVERFLOW\n");
			continue;
		}
		printf("%.2lf\n",work());
	}
	return 0;
}