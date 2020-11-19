#include<stdio.h>
#include<algorithm>
using namespace std;
int n,m;
int main()
{
	for(;scanf("%d%d",&n,&m),n+m;)
	{
		n+=2,m++;
		int g=__gcd(n,m);
		n/=g,m/=g;
		printf("%d %d\n",m,n);
	}
	return 0;
}
