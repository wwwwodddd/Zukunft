#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<time.h>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
struct P
{
	double x,y;
	void scan()
	{
		scanf("%lf %lf",&x,&y);
	}
}p[200020],ls[200020];
double ans;
int lc,n;
double dis(const P&a,const P&b)
{
	return hypot(a.x-b.x,a.y-b.y);
}
bool cmpx(const P&a,const P&b)
{
	return a.x<b.x||a.x==b.x&&a.y<b.y;
}
bool cmpy(const P&a,const P&b)
{
	return a.y<b.y||a.y==b.y&&a.x<b.x;
}
void ud(P a,P b,P c)
{
	ans=min(ans,dis(a,b)+dis(b,c)+dis(c,a));
}
void work(int l,int r)
{
	if(r-l<3)
		return sort(p+l,p+r,cmpy);
	int m=l+r>>1;
	double mx=p[m].x;
	work(l,m),work(m,r);
	inplace_merge(p+l,p+m,p+r,cmpy);
	lc=0;
	for(int i=l;i<r;i++)
		if(fabs(p[i].x-mx)<ans/2)
			ls[lc++]=p[i];
	for(int i=0;i<lc;i++)
		for(int j=i-1;j>=0&&ls[i].y-ls[j].y<ans/2;j--)
			for(int k=j-1;k>=0&&ls[i].y-ls[k].y<ans/2;k--)
				ud(ls[i],ls[j],ls[k]);
}
double rd()
{
	int n=rand()<<15|rand();
	return n*1e-4;
}
void mk()
{
	int n=100000;
	freopen("c.in","w",stdout);
	srand(time(0)); 
	printf("%d\n",n);
	for(int i=0;i<n;i++)
		printf("%.6f %.6f\n",rd(),rd());
}
int main()
{
//	mk();fclose(stdout);
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout);
	ans=1e30;
	scanf("%d",&n);
	fr(i,n)
		p[i].scan();
	sort(p,p+n,cmpx);
	work(0,n);
	printf("%.6f",ans);
	return 0;
}
