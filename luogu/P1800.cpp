#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[120], b[120];
int f[120][120];
bool ok(int t)
{
	memset(f, 0xc0, sizeof f);
	f[0][0] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			for (int k = 0; k + j <= m && k * a[i] <= t; k++)
			{
				f[i + 1][j + k] = max(f[i + 1][j + k], f[i][j] + (t - k * a[i]) / b[i]);
			}
		}
	}
	return f[n][m] >= m;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i];
	}
	int L = 0, R = 100000;
	while (L < R - 1)
	{
		int M = (L + R) / 2;
		if (ok(M))
		{
			R = M;
		}
		else
		{
			L = M;
		}
	}
	cout << R << endl;
	return 0;
}