#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
typedef long long ll;
int t, n;
ll pw(ll x, ll y)
{
	ll re = 1;
	for (; y > 0; y >>= 1)
	{
		if (y & 1)
		{
			re = re * x % p;
		}
		x = x * x % p;
	}
	return re;
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		printf("%lld\n", (pw(4, n) + 2 * p - pw(3, n) * 2 + pw(2, n)) % p);
	}
	return 0;
}