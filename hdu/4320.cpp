#include<stdio.h>
#include<algorithm>
using namespace std;
int t,k;
long long x,y;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%I64d %I64d",&x,&y);
		for(;__gcd(x,y)>1;)
			x/=__gcd(x,y);
		printf("Case #%d: ",++k);
		puts(x>1?"NO":"YES");
	}
	return 0;
}
