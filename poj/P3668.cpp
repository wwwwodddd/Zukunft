#include<iostream>
#include<algorithm>
using namespace std;
double a[40020];
double x[205],y[205];
int n,k,i,j,c;
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%lf%lf",&x[i],&y[i]);
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if(x[i]==x[j])
				a[k++]=2147483647;
			else
				a[k++]=(y[j]-y[i])/(x[j]-x[i]);
	sort(a,a+k);
	for(i=1;i<k;i++)
		if(a[i-1]!=a[i])
			c++;
	printf("%d\n",c+1);
	return 0;
}
