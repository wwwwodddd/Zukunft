#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int f[1020][1020];
int n, m, l, invm;
int pw(int x, int y)
{
	int re = 1;
	for (; y > 0; y >>= 1)
	{
		if (y & 1)
		{
			re = (long long)re * x % p;
		}
		x = (long long)x * x % p;
	}
	return re;
}
int main()
{
	cin >> n >> m >> l;
	invm = pw(m, p - 2);
	f[0][0] = 1;
	for (int i = 0; i < l; i++)
	{
		f[i + 1][n] = f[i][n];
		for (int j = 0; j < n; j++)
		{
			for (int k = 1; k <= m; k++)
			{
				int y = j + k;
				if (y > n)
				{
					y = 2 * n - y;
				}
				f[i + 1][y] = (f[i + 1][y] + (long long)f[i][j] * invm) % p;
			}
		}
	}
	cout << f[l][n] << endl;
	return 0;
}