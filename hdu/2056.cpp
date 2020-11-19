#include<stdio.h>
#include<iostream>
using namespace std;
double x1,x2,x3,x4,y1,y2,y3,y4;
int main()
{
	while(cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4)
	{
		if(x1>x2)
			swap(x1,x2);
		if(y1>y2)
			swap(y1,y2);
		if(x3>x4)
			swap(x3,x4);
		if(y3>y4)
			swap(y3,y4);
		x1=max(x1,x3);
		y1=max(y1,y3);
		x2=min(x2,x4);
		y2=min(y2,y4);
		if(x1>x2||y1>y2)
			puts("0.00");
		else
			printf("%.2f\n",(x2-x1)*(y2-y1));
	}
	return 0;
}
