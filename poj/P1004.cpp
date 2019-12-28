#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int i;
	double a,b=0.0;
	for(i=0;i<12;i++)
	{
	scanf("%lf",&a);
		b+=a;
	}
	printf("$%.2lf",b/12);
	return 0;
}