#include <bits/stdc++.h>
using namespace std;
int n, x[20], y[20], p[20], f[20];
long long z[20];
void dfs(int d, int t)
{
	if (d == n)
	{
		long long s = 0;
		for (int i = 0; i < n; i++)
		{
			s += (long long)f[i] * p[i];
		}
		z[t] = min(z[t], s);
		return;
	}
	dfs(d + 1, t);
	int g[20];
	memcpy(g, f, sizeof g);
	for (int i = 0; i < n; i++)
	{
		f[i] = min(f[i], abs(x[i] - x[d]));
	}
	dfs(d + 1, t + 1);
	memcpy(f, g, sizeof f);
	for (int i = 0; i < n; i++)
	{
		f[i] = min(f[i], abs(y[i] - y[d]));
	}
	dfs(d + 1, t + 1);
	memcpy(f, g, sizeof f);
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i] >> p[i];
		z[i] = 1e18;
		f[i] = min(abs(x[i]), abs(y[i]));
	}
	dfs(0, 0);
	for (int i = 0; i <= n; i++)
	{
		printf("%lld\n", z[i]);
	}
	return 0;
}