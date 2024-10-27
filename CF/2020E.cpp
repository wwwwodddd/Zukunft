#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int m = 10;
const int p = 1000000007;
ll f[2][2][20][20];
ll g[2][2][20][20];
ll a[200020];
ll b[200020];
int main()
{
	int t;
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		int n;
		cin >> n;
		memset(f, 0, sizeof f);
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				f[0][0][i][j] = 1;
			}
		}
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
			b[i] = b[i] * 285700002 % p;
		}
		for (int i = 0; i < n; i++)
		{
			memset(g, 0, sizeof g);
			for (int j = 0; j < m; j++)
			{
				for (int k = 0; k < m; k++)
				{
					for (int da = 0; da < 2; da++)
					{
						for (int db = 0; db < 2; db++)
						{
							g[da][db][j][k] = (g[da][db][j][k] + f[da][db][j][k] * (p + 1 - b[i])) % p;
							g[da ^ (a[i] >> j & 1)][db ^ (a[i] >> k & 1)][j][k] = (g[da ^ (a[i] >> j & 1)][db ^ (a[i] >> k & 1)][j][k] + f[da][db][j][k] * b[i]) % p;
						}
					}
				}
			}
			swap(f, g);
		}
		long long z = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				z = (z + (f[1][1][i][j] << i << j)) % p;
			}
		}
		cout << z << endl;
	}
	return 0;
}