#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int n, a[1020];
long long f[1020][1020];
long long g[1020][1020];
long long pw(long long x, long long y)
{
	if (x == 0 && y == 0)
	{
		return 0;
	}
	long long re = 1;
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
	int t;
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				f[i][j] = 0;
				g[i][j] = 0;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		for (int i = n; i > 0; i--)
		{
			for (int j = i + 1; j <= n; j++)
			{
				f[i][j] = max(f[i + 1][j] + pw(a[i], a[i + 1]), g[i + 1][j] + pw(a[i], a[j]));
				g[i][j] = max(f[i][j - 1] + pw(a[j], a[i]), g[i][j - 1] + pw(a[j], a[j - 1]));
			}
		}
		cout << max(f[1][n], g[1][n]) << endl;
	}
	return 0;
}