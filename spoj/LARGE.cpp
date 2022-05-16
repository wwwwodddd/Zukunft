#include <bits/stdc++.h>
using namespace std;
const int p = 100000007;
const int M = 2020;
int t, n, k;
int f[M];
int s[M];
int g[M];
int v[M];
int main()
{
	v[1] = 1;
	for (int i = 1; i < M; i++)
	{
		g[i] = i;
	}
	for (int i = 2; i < M; i++)
	{
		v[i] = (long long)v[p % i] * (p - p / i) % p;
		if (g[i] == i)
		{
			for (int j = i; j < M; j += i)
			{
				g[j] = g[j] / i * (i - 1);
			}
		}
	}
	for (scanf("%d", &t); t--;)
	{
		scanf("%d%d", &n, &k);
		k = min(k, n);
		f[1] = s[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			f[i] = (s[i - 1] + p - s[max(i - k - 2, 0)]) % p;
			s[i] = (s[i - 1] + f[i]) % p;
		}
		int z = 0;
		long long t = 0;
		for (int i = 1; i <= n; i++)
		{
			t = (t + s[i] + p - s[max(i - k - 1, 0)]) % p;
			if (i >= k + 1)
			{
				t = (t - (long long)f[i - k - 1] * (k + 1)) % p;
				if (t < 0)
				{
					t += p;
				}
			}
			if (n % i == 0)
			{
				z = (z + (long long)t * g[n / i]) % p;
			}
		}
		z = (long long)z * v[n] % p;
		if (k >= n)
			++z %= p;
		printf("%d\n", z);
	}
	return 0;
}