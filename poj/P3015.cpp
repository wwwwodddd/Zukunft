#include<stdio.h>
int n,m,a[50020];
int main()
{
	for(;scanf("%d%d",&n,&m),n+m;)
	{
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		double s=(double)m/(n-m+1),z=0;
		for(int i=0;i<=n-m;i++)
		{
			s=s/(n-i)*(n-m-i+1);
			z-=a[i]*s;
			z+=a[n-i-1]*s;
		}
		printf("%.3f\n",z);
	}
	return 0;
}
