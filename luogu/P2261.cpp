#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, z;
int main()
{
	scanf("%lld%lld", &n, &k);
	z = n * k;
	for (ll l = 1, r, a; l <= n; l = r + 1)
	{
		if ((a = k / l))
		{
			r = min(k / a, n);
		}
		else
		{
			r = n;
		}
		z -= a * (l + r) * (r - l + 1) / 2;
	}
	printf("%lld\n", z);
	return 0;
}