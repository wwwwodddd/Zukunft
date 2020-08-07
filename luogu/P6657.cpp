#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int t, n, m;
int a[100][100];
int x[100];
int y[100];
int f[2000020];
int v[2000020];
int C(int n, int m)
{
	return n < m ? 0 : (long long)f[n] * v[m] % mod * v[n - m] % mod;
}
int main()
{
	v[0] = v[1] = f[0] = 1;
	for (int i = 2; i < 2000010; i++)
	{
		v[i] = (long long)(mod - mod / i) * v[mod % i] % mod;
	}
	for (int i = 1; i < 2000010; i++)
	{
		f[i] = (long long)f[i - 1] * i % mod;
		v[i] = (long long)v[i - 1] * v[i] % mod;
	}
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &m, &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &x[i], &y[i]);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				a[i][j] = C(m - 1 + y[j] - x[i], m - 1);
			}
		}
		int ans = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				while (a[j][i])
				{
					int t = a[i][i] / a[j][i];
					for (int k = 0; k < n; k++)
					{
						a[i][k] = (a[i][k] - (long long)a[j][k] * t) % mod;
					}
					swap(a[i], a[j]);
					ans = -ans;
				}
			}
			ans = (long long)ans * a[i][i] % mod;
		}
		if (ans < 0)
		{
			ans += mod;
		}
		printf("%d\n", ans);
	}
	return 0;
}