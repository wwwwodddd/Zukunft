#include <bits/stdc++.h>
using namespace std;
int n, m, s;
int a[120][120];
int b[120][120];
bool ok(int r, int c)
{
	if (s % (r * c))
	{
		return false;
	}
	memset(b, 0, sizeof b);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
			if (a[i][j] < b[i][j])
			{
				return false;
			}
			if (a[i][j] > b[i][j])
			{
				if (i + r - 1 > n || j + c - 1 > m)
				{
					return false;
				}
				int u = a[i][j] - b[i][j];
				b[i][j] += u;
				b[i][j + c] -= u;
				b[i + r][j] -= u;
				b[i + r][j + c] += u;
			}
		}
	}
	return true;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
			s += a[i][j];
		}
	}
	int z = s;
	for (int r = 1; r <= n; r++)
	{
		for (int c = 1; c <= m; c++)
		{
			if (ok(r, c))
			{
				z = min(z, s / r / c);
			}
		}
	}
	printf("%d\n", z);
	return 0;
}