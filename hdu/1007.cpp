#include<iostream>
#include<algorithm>
#include<math.h>
#include<stdio.h>
using namespace std;
struct P{double x,y;}p[100020];
bool cmp(P a,P b)
{
	return a.x<b.x||a.x==b.x&&a.y<b.y;
}
double dist(P a,P b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double min_dis(int l,int r)
{
	int i,j;
	double re=1e30;
	if(r>l+10)
	{
		int m=(l+r)>>1;
		re=min(min_dis(l,m),min_dis(m+1,r));
		for(i=m;i>=l&&p[i].x>p[m].x-re;i--)
			for(j=m+1;j<=r&&p[j].x<p[m].x+re;j++)
				re=min(re,dist(p[i],p[j]));
	}
	else
	{
		for(i=l;i<r;i++)
			for(j=i+1;j<=r;j++)
				re=min(re,dist(p[i],p[j]));
	}
	return re;
}
int n,t,i,j,k;
int main()
{
	for(;scanf("%d",&n),n;)
	{
		for(i=0;i<n;i++)
			scanf("%lf%lf",&p[i].y,&p[i].x);
		sort(p,p+n,cmp);
		printf("%.2f\n",min_dis(0,n-1)/2);
	}
	return 0;
}
