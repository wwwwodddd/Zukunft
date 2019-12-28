#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
double r,x11,x22,x33,y11,y22,y33,z11,z22,z33;
int t;
const double pi=3.1415926535;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf %lf %lf %lf %lf %lf %lf",&r,&x11,&y11,&x22,&y22,&x33,&y33);
		if(x11==0&&y11==0||x22==0&&y22==0||x33==0&&y33==0)
		{
			printf("%s\n","No");
			continue;
		}
		z11=atan2(y11,x11);
		z22=atan2(y22,x22);
		z33=atan2(y33,x33);
		if(z11<z22)
			swap(z11,z22);
		if(z22<z33)
			swap(z22,z33);
		if(z11<z22)
			swap(z11,z22);
		if(z11-z33<2*pi/3||z22-z11+pi*2<2*pi/3||z33-z22+pi*2<2*pi/3)
			printf("%s\n","No");
		else
			printf("%s\n","Yes");
	}
	return 0;
}