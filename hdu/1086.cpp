#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
double eps=1e-8;
struct P
{
	double x,y;
	void scan()
	{
		scanf("%lf%lf",&x,&y);	
	}
}p[120][2];
int n;
int sgn(double x)
{
	return x<-eps?-1:x>eps;
}
double xm(P a,P b,P c)
{
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);	
}
int sgx(P a,P b,P c)
{
	return sgn(xm(a,b,c));	
}
int ok(P a,P b,P c,P d)
{
	if(min(a.x,b.x)<=max(c.x,d.x)&&min(c.x,d.x)<=max(a.x,b.x)&&min(a.y,b.y)<=max(c.y,d.y)&&min(c.y,d.y)<=max(a.y,b.y))
		if(sgx(a,b,c)*sgx(a,b,d)<=0&&sgx(c,d,a)*sgx(c,d,b)<=0)
			return 1;
	return 0;		
}
int main()
{
	for(;scanf("%d",&n),n;)
	{
		int z=0;
		fr(i,n)
			p[i][0].scan(),p[i][1].scan();
		fr(i,n)
			fr(j,i)
				z+=ok(p[i][0],p[i][1],p[j][0],p[j][1]);
		printf("%d\n",z);
	}
}
