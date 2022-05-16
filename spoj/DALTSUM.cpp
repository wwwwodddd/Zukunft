#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int n;
long long x, z = -1e18;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &x);
		z = max(z, x);
	}
	z = (z % p + p) % p;
	for (int i = 1; i < n; i++)
	{
		z = z * 2 % p;
	}
	printf("%lld\n", z);
	return 0;
}