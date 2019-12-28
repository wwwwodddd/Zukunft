#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
using namespace std;
#define F for(int i=0;i<p&&t;i++,t--)
int n,m,t,p,xa,ya,xb,yb,dx,dy;
int K(int n,int &x,int &y)
{
	p=(int)(sqrt(12*n-3.0)-3)/6;
	t=n-(3*p*p+3*p+1);
	x=p;
	y=0;
	p++;
	while(t)
	{
		x++;
		F x--,y++;
		F x--;
		F y--;
		F x++,y--;
		F x++;
		F y++;
	}
}
int main()
{
	while(scanf("%d %d",&n,&m),n+m)
	{
		K(n,xa,ya);
		K(m,xb,yb);
		dx=xa-xb;
		dy=ya-yb;
		printf("The distance between cells %d and %d is %d.\n",n,m,max(abs(dx+dy),max(abs(dx),abs(dy))));
	}
	return 0;
}
