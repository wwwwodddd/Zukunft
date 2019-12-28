#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
double eps=1E-8;
struct P{int x,y;}p[30];
int f[30];
int n,i,j,k;
int sgn(int x)
{
	return (x>0)-(x<0);
}
int xm(P a,P b,P c)
{
	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
int intersect(P a,P b,P c,P d)
{
	return max(a.x,b.x)>=min(c.x,d.x)&&max(c.x,d.x)>=min(a.x,b.x)&&max(a.y,b.y)>=min(c.y,d.y)&&max(c.y,d.y)>=min(a.y,b.y)&&(sgn(xm(a,b,c))*sgn(xm(a,b,d)))<=0&&(sgn(xm(c,d,a))*sgn(xm(c,d,b)))<=0;
}
int F(int x)
{
	if(f[x]==x)
		return x;
	return f[x]=F(f[x]);
}
void U(int x,int y)
{
	f[F(x)]=F(y);
}
int main()
{
	while(scanf("%d",&n),n)
	{
		for(i=0;i<=n;i++)
			f[i]=i;
		for(i=0;i<2*n;i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				if(i!=j&&intersect(p[i*2],p[i*2+1],p[j*2],p[j*2+1]))
					U(i+1,j+1);
		while(scanf("%d %d",&i,&j),i+j)
			printf("%sCONNECTED\n",F(i)==F(j)?"":"NOT ");
	}
	return 0;
}