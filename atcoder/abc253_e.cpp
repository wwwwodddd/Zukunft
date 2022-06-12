#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int n, m, l, z;
int f[1020][5020];
int s[1020][5020];
int main()
{
	cin >> n >> m >> l;
	for (int i = 1; i <= m; i++)
	{
		f[1][i] = 1;
		s[1][i] = (s[1][i - 1] + f[1][i]) % p;
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (l > 0)
			{
				f[i][j] = (s[i - 1][max(j - l, 0)] + (s[i - 1][m] - s[i - 1][min(j + l - 1, m)])) % p;			
			}
			else
			{
				f[i][j] = s[i - 1][m];
			}
			if (f[i][j] < 0)
			{
				f[i][j] += p;
			}
			s[i][j] = (s[i][j - 1] + f[i][j]) % p;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		z = (z + f[n][i]) % p;
	}
	cout << z << endl;
	return 0;
}
