#include<stdio.h>
#include<math.h>
double a[10000020];
double pi=acos(-1.);
int t;
long long n;
int main()
{
	a[0]=1;
	for(int i=1;i<10000000;i++)
		a[i]=a[i-1]*(i*2)/(i*2+1);
	for(scanf("%d",&t);t--;)
	{
		scanf("%lld",&n);
		if(n<10000000)
			printf("%.6e\n",a[n]);
		else
			printf("%.6le\n",sqrt(pi/(4*n)));
	}
}
