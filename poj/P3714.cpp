#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
#define INF 1e100
struct P{double x,y;int r;}p[200005];
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
	double ll=0,rr=0,re=INF;
	if(r>l+2)
	{
		int z=(l+r)>>1;
		ll=min_dis(l,z);
		rr=min_dis(z,r);
		re=ll<rr?ll:rr;
		for(i=z;i>=l&&p[i].x>p[z].x-re;i--)
			for(j=z;j<=r&&p[j].x<p[z].x+re;j++)
				if(p[i].r!=p[j].r)
					re=min(re,dist(p[i],p[j]));
	}
	else
	{
		double dis;
		for(i=l;i<r;i++)
			for(j=i+1;j<=r;j++)
				if(p[i].r!=p[j].r)
					re=min(re,dist(p[i],p[j]));
	}
	return re;
}
int n,t,i,j,k;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<2*n;i++)
		{
			scanf("%lf%lf",&p[i].x,&p[i].y);
			p[i].r=(i<n)+1;
		}
		n*=2;
		sort(p,p+n,cmp);
		printf("%.3f\n",min_dis(0,n-1));
	}
	return 0;
}