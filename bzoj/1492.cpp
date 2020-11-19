#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
using namespace std;
double eps=1e-10;
int sgn(double x)
{
	return x<eps?-1:x>eps; 
}
struct D
{
	double a,b;
	int r;
}d[100020],ds[100020];
bool operator<(D a,D b)
{
	return a.a*b.b>a.b*b.a;	
}
struct P
{
	double x,y;	
}p[100020],ps[100020],s[100020];
bool operator<(P a,P b)
{
	if(sgn(a.x-b.x))
		return a.x<b.x;
	return a.x<b.x; 
}
double xm(P a,P b,P c)
{
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
double st,rt[100020],f[100020];
void work(int l,int r)
{
//	printf("%d %d\n",l,r);
	if(l==r)
	{
		f[l]=max(f[l],f[l-1]);
		double nb=f[l]/(d[l].a*rt[l]+d[l].b),na=nb*rt[l];
		p[l]=(P){na,nb};
		return;
	}
	int m=(l+r)/2,i,j,k;
	for(i=l,j=m+1,k=l;k<=r;k++)
		if(d[k].r<=m)
			ds[i++]=d[k];
		else
			ds[j++]=d[k];
	for(i=l;i<=r;i++)
		d[i]=ds[i];
	work(l,m);
	s[0]=p[l];
	for(i=l+1,j=0;i<=m;i++)
	{
		for(;j&&sgn(xm(s[j-1],s[j],p[i]))>=0;j--)
			;
		s[++j]=p[i];
	}
	for(i=m+1;i<=r;i++)
	{
		D u=d[i];
		for(;j&&sgn(u.b*(s[j].y-s[j-1].y)+u.a*(s[j].x-s[j-1].x))<0;j--)
			;
		f[u.r]=max(f[u.r],u.a*s[j].x+u.b*s[j].y);
	}
	work(m+1,r);
	for(i=l,j=m+1,k=l;i<=m||j<=r;k++)
	{
		if(j>r||i<=m&&p[i]<p[j])
			ps[k]=p[i++];
		else
			ps[k]=p[j++];
	}
	for(i=l;i<=r;i++)
		p[i]=ps[i];
}
int main()
{
	int n;
	scanf("%d%lf",&n,f);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf%lf",&d[i].a,&d[i].b,rt+i);
		d[i].r=i;
	}
	sort(d+1,d+n+1);
	work(1,n);
	printf("%.3f",f[n]);
	return 0;	
}
