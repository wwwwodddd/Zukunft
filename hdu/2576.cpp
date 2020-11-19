#include<stdio.h>
int t;
long long n,a[3];
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%I64d",&n);
		for(int i=0;i<3;i++)
			a[i]=n+i;
		a[n%2]/=2;
		a[2-(n-1)%3]/=3;
		printf("%I64d\n",a[0]*a[1]%20090524*a[2]%20090524);
	}
	return 0;
}
