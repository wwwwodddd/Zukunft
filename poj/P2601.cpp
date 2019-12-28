#include<stdio.h>
int n;
double a[10020],st,ed,c[10020];
int main()
{
	scanf("%d",&n);
	scanf("%lf%lf",&st,&ed);
	for(int i=1;i<=n;i++)
		scanf("%lf",c+i);
	double L=-1000,R=1000;
	for(int _=0;_<100;_++)
	{
		double M=(L+R)*.5;
		a[0]=st;
		a[1]=M;
		for(int i=1;i<=n;i++)
			a[i+1]=a[i]*2-a[i-1]+2*c[i];
		if(a[n+1]>ed)
			R=M;
		else
			L=M;
	}
	printf("%.2f\n",L);
}
