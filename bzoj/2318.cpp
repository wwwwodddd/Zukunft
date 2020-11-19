#include<stdio.h>
#include<iostream>
using namespace std;
double a[220],b[220],p,q;
int t,n;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %lf %lf",&n,&p,&q);
		a[0]=0;
		b[0]=1;
		n=min(n,200);
		for(int i=0;i<n;i++)
		{
			if(a[i]<b[i])
			{
				a[i+1]=(p*b[i]+(1-p)*q*a[i])/(1-(1-p)*(1-q));
				b[i+1]=(q*a[i]+(1-q)*p*b[i])/(1-(1-p)*(1-q));
			}
			else
			{
				a[i+1]=((1-p)*b[i]+(1-q)*p*a[i])/(1-p*q);
				b[i+1]=((1-q)*a[i]+(1-p)*q*b[i])/(1-p*q);
			}
		}
		printf("%.6f\n",a[n]);
	}
}
