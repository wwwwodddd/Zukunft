#include<iostream>
using namespace std;
struct P{double x,y;}p[220];
int sgn(int x)
{
	return (x>0)-(x<0);
}
int xm(P a,P b,P c)
{
	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
int is(P a,P b,P c,P d)
{
	return max(a.x,b.x)>=min(c.x,d.x)&&max(c.x,d.x)>=min(a.x,b.x)&&max(a.y,b.y)>=min(c.y,d.y)&&max(c.y,d.y)>=min(a.y,b.y)&&(sgn(xm(a,b,c))*sgn(xm(a,b,d)))<=0&&(sgn(xm(c,d,a))*sgn(xm(c,d,b)))<=0;
}
int l[110],i,j,k,n;
int main()
{
	scanf("%d",&n);
	for(i=0;i<2*n;i++)
		scanf("%lf%lf",&p[i].x,&p[i].y);
	for(i=0;i<n;i++)
		l[i]=n+i;
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				if(is(p[i],p[l[i]],p[j],p[l[j]]))
					swap(l[i],l[j]);
	for(i=0;i<n;i++)
		printf("%d\n",l[i]-n+1);
	return 0;
}