#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, z;
int a[3020];
int b[3020];
int f[3020][3020];
int main()
{
	for (int j = 0; j < 3010; j++)
	{
		f[0][j] = 1;
	}
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = a[i]; j <= b[i]; j++)
		{
			f[i][j] = f[i - 1][j];
		}
		for (int j = 1; j < 3010; j++)
		{
			f[i][j] = (f[i][j] + f[i][j - 1]) % mod;
		}
	}
	cout << f[n][3000] << endl;
	return 0;
}
