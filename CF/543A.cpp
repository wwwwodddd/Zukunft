#include <bits/stdc++.h>
using namespace std;
int n, m, l, mod, x, z;
int f[520][520];
int main()
{
	cin >> n >> m >> l >> mod;
	f[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		for (int j = 1; j <= m; j++)
		{
			for (int k = x; k <= l; k++)
			{
				f[j][k] = (f[j][k] + f[j - 1][k - x]) % mod;
			}
		}
	}
	for (int k = 0; k <= l; k++)
	{
		z = (z + f[m][k]) % mod;
	}
	cout << z << endl;
	return 0;
}