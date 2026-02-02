#include <bits/stdc++.h>
using namespace std;
const int M = 20;
int l, m, n, k;
int a[100020];
int64_t d[20];
int64_t f[524289][19];
void checkmin(int64_t &x, int64_t y)
{
	x = min(x, y);
}
int64_t dist(int64_t x, int64_t y)
{
	int64_t d = (x - y + l) % l;
	int64_t z = (d * k + k) / (k + 1);
	if (k > 1)
	{
		z = min(z, ((l - d) * k + k - 2) / (k - 1));
	}
	return z;
}
int64_t get_time(int i, int64_t t)
{
	int64_t p = (l / m * (i + 1) + (t + k - 1) / k) % l;
	int64_t d = *lower_bound(a, a + n + 1, p) - p;
	return k * (d + (t + k - 1) / k);
}
int main()
{
	scanf("%d%d%d%d", &l, &m, &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	a[n] = a[0] + l;
	memset(f, 0x3f, sizeof f);
	for (int i = 0; i < m; i++)
	{
		d[i] = dist(0, l / m * i);
	}
	for (int i = 0; i < (m - 1); i++)
	{
		f[1 << i][i] = d[i + 1];
	}
	for (int i = 0; i < 1 << (m - 1); i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			if (i >> j & 1)
			{
				f[i][j] = get_time(j, f[i][j]);
				for (int k = 0; k < m - 1; k++)
				{
					if (~i >> k & 1)
					{
						checkmin(f[i | 1 << k][k], f[i][j] + d[(k - j + m) % m]);
					}
				}
			}
		}
	}
	printf("%lld\n", *min_element(f[(1 << (m - 1)) - 1], f[(1 << (m - 1)) - 1] + (m - 1)));
	return 0;
}