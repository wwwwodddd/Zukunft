#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int t, n, m;
int f[520][520];
int main()
{
	f[0][0] = 1;
	for (int i = 0; i < 510; i++)
	{
		for (int j = 0; j < 510; j++)
		{
			f[i + 0][j + 1] = (f[i + 0][j + 1] + f[i][j]) % mod;
			f[i + 1][j + 1] = (f[i + 1][j + 1] + f[i][j]) % mod;
			f[i + 2][j + 1] = (f[i + 2][j + 1] + f[i][j]) % mod;
		}
	}
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> m;
		cout << f[n][m] << endl;
	}
	return 0;
}