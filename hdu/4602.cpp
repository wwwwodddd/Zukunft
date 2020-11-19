#include<stdio.h>
typedef long long ll;
int t,n,k,p=1000000007;
ll pw(ll x,ll y)
{
	ll z=1;
	for(;y;y>>=1,x=x*x%p)
		if(y&1)
			z=z*x%p;
	return z;
}
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d%d",&n,&k);
		if(n<k)
			puts("0");
		else if(n==k)
			puts("1");
		else if(n==k+1)
			puts("2");
		else
			printf("%d\n",int(pw(2,n-k-2)*(n-k+3)%p));
	}
}
