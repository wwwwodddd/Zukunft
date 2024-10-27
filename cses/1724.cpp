#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int n, m, k;
long long a[120][120];
long long b[120][120];
void mul(long long a[120][120], long long b[120][120])
{
	long long c[120][120] = {};
	memset(c, 0x3f, sizeof c);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				c[i][j] = min(c[i][j], a[i][k] + b[k][j]);
			}
		}
	}
	memcpy(a, c, sizeof c);
}
int main()
{
	cin >> n >> m >> k;
	memset(a, 0x3f, sizeof a);
	for (int i = 1; i <= n; i++)
	{
		a[i][i] = 0;
	}
	memset(b, 0x3f, sizeof b);
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		b[x][y] = min(b[x][y], (long long)z);
	}
	for (; k > 0; k >>= 1)
	{
		if (k & 1)
		{
			mul(a, b);
		}
		mul(b, b);
	}
	if (a[1][n] > 1e18)
	{
		a[1][n] = -1;
	}
	cout << a[1][n] << endl;
	return 0;
}