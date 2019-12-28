#include<stdio.h>
#include<math.h>
int n;
double k[120],x,u=1e9;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lf",k+i);
		if(k[i]<u)
			u=k[i];
	}
	scanf("%lf",&x);
	if(sin(x)*k[0]/u>1.)
		puts("NO");
	else
		printf("%.4f\n",asin(sin(x)*k[0]/k[n-1]));
	return 0;
}
