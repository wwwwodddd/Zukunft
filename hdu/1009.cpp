#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct N
{
	int x,y;
	double k;
}a[3001];
bool cmp(N a,N b)
{
	return a.k>b.k;
}
int n,m;
double z;
int main()
{
	while(scanf("%d%d",&m,&n),n+m+2)
	{
		z=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a[i].x,&a[i].y);
			a[i].k=(double)a[i].x/a[i].y;
		}
		sort(a,a+n,cmp);
		for(int i=0;i<n;i++)
		{
			if(m>a[i].y)
			{
				z+=a[i].x;
				m-=a[i].y;
			}
			else
			{
				z+=a[i].k*m;
				m=0;
				break;
			}
		}
		printf("%.3f\n",z);
	}
	return 0;
}
