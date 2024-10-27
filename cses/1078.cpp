#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int n, m, x, z;
int f[2000020];
int v[2000020];
pair<int, int> a[1020];
int g[1020];
int C(int x, int y)
{
	return (long long)f[x + y] * v[x] % p * v[y] % p;
}
int main()
{
	cin >> n >> m;
	f[0] = 1;
	v[0] = v[1] = 1;
	for (int i = 2; i <= 2 * n; i++)
	{
		v[i] = (long long)v[p % i] * (p - p / i) % p;
	}
	for (int i = 1; i <= 2 * n; i++)
	{
		f[i] = (long long)f[i - 1] * i % p;
		v[i] = (long long)v[i - 1] * v[i] % p;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a + m);
	a[m] = make_pair(n, n);
	for (int i = 0; i <= m; i++)
	{
		g[i] = C(a[i].first - 1, a[i].second - 1);
		for (int j = 0; j < i; j++)
		{
			if (a[j].second <= a[i].second)
			{
				g[i] = (g[i] - (long long)g[j] * C(a[i].first - a[j].first, a[i].second - a[j].second)) % p;
				if (g[i] < 0)
				{
					g[i] += p;
				}
			}
		}
	}
	cout << g[m] << endl;
	return 0;
}