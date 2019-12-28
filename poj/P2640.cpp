#include <iostream>
#include <algorithm>
using namespace std;
double f[30];
int i,n;
int main()
{
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
			scanf("%lf",&f[i]);
		sort(f,f+n);
		double sum=0;
		for(i=0;i<n;sum+=f[i++])
			if(sum>=f[i])
				break;
		puts(i!=n?"YES":"NO");
	}
	return 0;
}
