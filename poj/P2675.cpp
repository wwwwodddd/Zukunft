#include<stdio.h>
#include<algorithm>
int z[90000],r[90000],n;
double x[90000],y[90000];
bool cmp(const int&a,const int&b)
{
	return x[b]*y[a]<x[a]*y[b];
}
int main()
{
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;i++)
			scanf("%d %lf %lf",z+i,y+i,x+i),r[i]=i;
		std::sort(r,r+n,cmp);
		scanf("%d",&n);
		printf("%d\n",z[r[n-1]]);
	}
	return 0;
}
