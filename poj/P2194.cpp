#include<stdio.h>
#include<math.h>
#include<algorithm>
int n;
double a[1020],y;
int main()
{
	for(;scanf("%d",&n),n;)
	{
		for(int i=0;i<n;i++)
			scanf("%lf",a+i);
		std::sort(a,a+n);
		y=2;
		for(int i=1;i<n;i++)
			y+=sqrt(16-(a[i]-a[i-1])*(a[i]-a[i-1]));
		printf("%.4f %.4f\n",(a[0]+a[n-1])/2,y/2);
	}
	return 0;
}
