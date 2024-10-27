#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int n, m, k;
int a[120][120];
int b[120][120];
void mul(int a[120][120], int b[120][120])
{
	int c[120][120] = {};
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				c[i][j] = (c[i][j] + (long long)a[i][k] * b[k][j]) % p;
			}
		}
	}
	memcpy(a, c, sizeof c);
}
int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		a[i][i] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		b[x][y]++;
	}
	for (; k > 0; k >>= 1)
	{
		if (k & 1)
		{
			mul(a, b);
		}
		mul(b, b);
	}
	cout << a[1][n] << endl;
	return 0;
}