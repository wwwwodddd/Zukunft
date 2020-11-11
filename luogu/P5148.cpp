#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int n, m, k, a;
long long q, x = 1, y = 1, z;
int inv(int x)
{
	return x == 1 ? 1 : (long long)(p - p / x) * inv(p % x) % p;
}
int main()
{
	scanf("%d%d%d%lld", &n, &m, &k, &q);
	q %= p;
	for (int i = 0; i <= m; i++)
	{
		scanf("%d", &a);
		z = (z + a * x) % p;
		x = x * q % p;
	}
	for (int i = 0; i < k; i++)
	{
		z = z * (n - i) % p;
		y = y * (i + 1) % p;
	}
	printf("%lld\n", z * inv(y) % p);
	return 0;
}