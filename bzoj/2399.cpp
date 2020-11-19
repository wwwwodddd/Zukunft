#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#define X first
#define Y second
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
double eps=1e-6;
struct L
{
	double x1,x2,y1,y2,k,b;
	char s[2];
}a[320];
typedef pair<double,double> dd;
dd b[320];
int bc,n;
double R,B,G,len;
int sgn(double x)
{
	return x<-eps?-1:x>eps;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lf %lf %lf %lf %s",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2,a[i].s);
		if(sgn(a[i].x1-a[i].x2)==0)
		{
			i--,n--;
			continue;
		}
		if(a[i].x1>a[i].x2)
			swap(a[i].x1,a[i].x2),swap(a[i].y1,a[i].y2);
		a[i].k=(a[i].y2-a[i].y1)/(a[i].x2-a[i].x1);
		a[i].b=a[i].y1-a[i].k*a[i].x1;
	}
	for(int i=0;i<n;i++)
	{
		len=a[i].x2-a[i].x1;
		bc=0;
		for(int j=0;j<n;j++)
			if(i!=j)
			{
				double lx=max(a[i].x1,a[j].x1);
				double rx=min(a[i].x2,a[j].x2);
				double ly=lx*a[j].k+a[j].b;
				double ry=rx*a[j].k+a[j].b;
				double Ly=lx*a[i].k+a[i].b;
				double Ry=rx*a[i].k+a[i].b;
				if(sgn(lx-rx)>=0)
					continue;
				if(sgn(ly-Ly)>=0&&sgn(ry-Ry)>=0)
					continue;
				else if(sgn(ly-Ly)<=0&&sgn(ry-Ry)<=0)
					b[bc++]=dd(lx,rx);
				else
				{
					double mx=(a[i].b-a[j].b)/(a[j].k-a[i].k);
					if(sgn(ly-Ly)<0)
						b[bc++]=dd(lx,mx);
					else
						b[bc++]=dd(mx,rx);
				}
			}
		sort(b,b+bc);
		double st=b[0].X,ed=b[0].X;
		for(int j=0;j<bc;j++)
			if(b[j].X>ed)
				len-=ed-st,st=b[j].X,ed=b[j].Y;
			else
				ed=max(ed,b[j].Y);
		len-=ed-st;
		if(*a[i].s=='R')
			R+=len;
		if(*a[i].s=='G')
			G+=len;
		if(*a[i].s=='B')
			B+=len;
	}
	printf("R %.2f\nG %.2f\nB %.2f\n",R,G,B);
}
