#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
const int N = 1000000;
long long f[N + 1];
long long g[N + 1];
long long v[N + 1];
int t, n, m;
int inv(int x)
{
	return x == 1 ? 1 : (long long)(p - p / x) * inv(p % x) % p;
}
int main()
{
	f[0] = 1;
	g[0] = 1;
	for (int i = 1; i <= N; i++)
	{
		f[i] = f[i - 1] * i % p;
		g[i] = g[i - 1] * i % p;
		if (i & 1)
		{
			g[i] = (g[i] + p - 1) % p;
		}
		else
		{
			g[i] = (g[i] + 1) % p;
		}
	}
	v[N] = inv(f[N]);
	for (int i = N; i > 0; i--)
	{
		v[i - 1] = v[i] * i % p;
	}
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &m);
		printf("%lld\n", f[n] * v[m] % p * v[n - m] % p * g[n - m] % p);
	}
	return 0;
}