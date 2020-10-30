#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int f[10000020];
int g[10000020];
int p[10000020];
int v[10000020];
int inv[10000020];
int main()
{
	int t, n = 10000010;
	f[1] = 1;
	p[0] = 1;
	inv[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (!v[i])
		{
			for (int j = i; j <= n; j += i)
			{
				v[j] = i;
			}
		}
		if (v[i / v[i]] == v[i])
		{
			f[i] = f[i / v[i]] * v[i];
		}
		else
		{
			f[i] = f[i / v[i]] * (v[i] - 1);
		}
		inv[i] = (long long)inv[mod % i] * (mod - mod / i) % mod;
	}
	for (int i = 1; i <= n; i++)
	{
		p[i] = p[i - 1] * 2 % mod;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j += i)
		{
			g[j] = (g[j] + (long long)f[i] * p[j / i]) % mod;
		}
		g[i] = (long long)g[i] * inv[i] % mod;
	}
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		printf("%d\n", g[n]);
	}
	return 0;
}