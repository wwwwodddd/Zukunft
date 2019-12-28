#include<stdio.h>
int a,p,n,k;
int main()
{
	while(scanf("%d %d",&p,&n)&&n+p)
	{
		a=1;
		while(n)
		{
			a*=n%p+1;
			a%=10000;
			n/=p;
		}
		printf("Case %d: %04d\n",++k,a);
	}
	return 0;
}