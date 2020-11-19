#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<assert.h>
#include<vector>
using namespace std;
double eps=1e-8;
int sgn(double x)
{
	return x<-eps?-1:x>eps;
}
struct P3
{
	double x,y,z;
	P3(){}
	P3(double x,double y,double z):x(x),y(y),z(z){}
	P3 operator +(P3 a)
	{
		return P3(x+a.x,y+a.y,z+a.z);
	}
	P3 operator -(P3 a)
	{
		return P3(x-a.x,y-a.y,z-a.z);
	}
	P3 operator *(double f)
	{
		return P3(x*f,y*f,z*f);
	}
	P3 operator /(double f)
	{
		return P3(x/f,y/f,z/f);
	}
	double dot(P3 a)
	{
		return x*a.x+y*a.y+z*a.z;
	}
	P3 det(P3 a)
	{
		return P3(y*a.z-z*a.y,z*a.x-x*a.z,x*a.y-y*a.x);
	}
	double abs()
	{
		return sqrt(x*x+y*y+z*z);
	}
	P3 nom()
	{
		return *this/abs();
	}
	void print()
	{
		printf("%.6lf %.6lf %.6lf\n");
	}
}

//need to do