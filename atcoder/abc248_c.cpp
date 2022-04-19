#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int n, m, l, z;
int f[51][2501];
int main()
{
	cin >> n >> m >> l;
	f[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i * m; j++)
		{
			for (int k = 1; k <= m; k++)
			{
				f[i + 1][j + k] = (f[i + 1][j + k] + f[i][j]) % p;
			}
		}
	}
	for (int i = 0; i <= l; i++)
	{
		z = (z + f[n][i]) % p;
	}
	cout << z << endl;
	return 0;
}
