#include<stdio.h>
#include<math.h>
double a[10020],pi=acos(-1.);
int t,n,m;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;i++)
			scanf("%lf",a+i),a[i]*=a[i]*pi;
		double l=0,r=1e30;
		for(int _=0;_<300;_++)
		{
			double k=(l+r)/2;
			int o=0;
			for(int i=0;i<n;i++)
				o+=a[i]/k;
			(o>m?l:r)=k;
		}
		printf("%.4lf\n",(l+r)/2);
	}
	return 0;
}
