#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
const double pi=acos(-1.0);
struct N{double v,u,x,y,z,a,b;}a[1005];
double dis(N a,N b)
{
return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}
int main()
{
	int n,i,j,z;
	double mx,mn;
	while(scanf("%d",&n)+1)
	{
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf",&a[i].v,&a[i].u);
			a[i].v*=pi/180;
			a[i].u*=pi/180;
			a[i].x=cos(a[i].v)*cos(a[i].u);
			a[i].y=cos(a[i].v)*sin(a[i].u);
			a[i].z=sin(a[i].v);
		}
		mn=1E30;
		for(i=0;i<n;i++)
		{
			mx=0;
			for(j=0;j<n;j++)
				mx=max(mx,dis(a[i],a[j]));
			if(mx<mn)
			{
				mn=mx;
				z=i;
			}
		}
		printf("%.2lf %.2lf\n",a[z].v/pi*180,a[z].u/pi*180);
	}
	return 0;
}