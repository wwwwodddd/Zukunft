#include<stdio.h>
typedef long long ll;
int t;
ll n;
ll T(ll n)
{
	return n*n*n;
}
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%I64d",&n);
		printf("%I64d %I64d\n",T(n),T(n+1));
	}
}
