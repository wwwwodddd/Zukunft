#include<stdio.h>
int F(int x,int y)
{
	int re=(x>>(y+1))<<y;
	if(x&(1<<y))
		return re+(x&((1<<y)-1));
	else
		return re;
}
int main()
{
	int t,n;
	for(scanf("%d",&t);t--;)
	{
			double z=0;
		scanf("%d",&n);
		for(int i=0;i<31;i++)
		{
			int u=F(n,i);
			z+=2.*u*(n-u)/n/n*(1<<i);
		}
		printf("%.2f\n",z);
	}
	return 0;
}

