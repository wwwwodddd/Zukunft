#include<stdio.h>
typedef long long ll;
ll L,R,M,n;
int v[200020];
int f[200020];
ll C(ll n)
{
	ll z=0;
	for(ll i=2;i*i<=n;i++)
		if(f[i])
			z+=n/i/i*f[i];
	return z;
}
int main()
{
	L=0,R=40000000000LL;
	for(int i=2;i<200010;i++)
		if(!v[i])
			for(int j=i;j<200010;j+=i)
				v[j]=i;
	f[1]=-1;
	for(int i=2;i<200010;i++)
		if(v[i]!=v[i/v[i]])
			f[i]=-f[i/v[i]];
	scanf("%lld",&n);
	for(;L<R-1;)
	{
		M=L+R>>1;
		if(C(M)<n)
			L=M;
		else
			R=M;
	}
	printf("%lld",R);
	return 0;
}
