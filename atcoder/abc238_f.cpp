#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int n, m;
int b[320];
int a[320];
int f[320][320][320];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> a[b[i]];
	}
	f[0][0][n + 1] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			for (int k = 1; k <= n + 1; k++)
			{
				int &t = f[i][j][min(k, a[i])];
				t = (t + f[i-1][j][k]) % p;
				if (a[i] < k && j < m)
				{
					f[i][j+1][k] = (f[i][j+1][k] + f[i-1][j][k]) % p;
				}
			}
		}
	}
	int z = 0;
	for (int i = 1; i <= n + 1; i++)
	{
		z = (z + f[n][m][i]) % p;
	}
	cout << z << endl;
	return 0;
}