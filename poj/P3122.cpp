#include<stdio.h>
#include<algorithm>
using namespace std;
const double pi=3.141592653589793;
double s[10020];
int n,f,t,i,j;
double l,h;
bool check(double x)
{
	int i,t,z=f;
	for(i=n-1;i>=0;i--)
	{
		t=(int)(s[i]/x);
		if(t<1)
			break;
		z-=t;
	}
	return z<0;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&f);
		for(i=0;i<n;i++)
		{
			scanf("%d",&j);
			s[i]=j*j*pi;
		}
		sort(s,s+n);
		l=0;
		h=s[n-1];
		while(h-l>=0.00001)
			check((l+h)/2)?l=(l+h)/2:h=(l+h)/2;
		printf("%.4lf\n",h);
	}
	return 0;
}
