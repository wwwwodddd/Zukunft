#include<stdio.h>
int i,n,a;
double t,dp,p;
int main()
{
	while(scanf("%d%lf",&n,&t),n+t)
	{
		dp=1<<n;
		for(i=1;i<=n;i++)
		{
			a=1<<(n-i);
			p=a/dp;
			if(p<t)
				dp*=(1+t)/2;
			else
				dp=(a*(p-t)+dp*(1-p*p)/2)/(1-t);
		}
		printf("%.3lf\n",dp);
	}
	return 0;
}
