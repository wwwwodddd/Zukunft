#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int n;
int c[520][520];
long long f[520][520];
char s[520];
int main()
{
	cin >> s;
	n = strlen(s);
	for (int i = 0; i <= n; i++)
	{
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % p;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		f[i][i - 1] = 1;
	}
	for (int l = 2; l <= n; l += 2)
	{
		for (int i = 0; i + l <= n; i++)
		{
			int j = i + l - 1;
			for (int k = i + 1; k <= j; k += 2)
			{
				if (s[i] == s[k])
				{
					f[i][j] = (f[i][j] + f[i + 1][k - 1] * f[k + 1][j] % p * c[l / 2][(j - k) / 2]) % p;
				}
			}
		}
	}
	cout << f[0][n - 1] << endl;
	return 0;
}