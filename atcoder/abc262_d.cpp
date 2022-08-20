#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int n, z;
int a[120];
int f[120][120][120];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		memset(f, 0, sizeof f);
		f[0][0][0] = 1;
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				for (int l = 0; l < i; l++)
				{
					f[j + 1][k][l] = (f[j + 1][k][l] + f[j][k][l]) % p;
					f[j + 1][k + 1][(l + a[j]) % i] = (f[j + 1][k + 1][(l + a[j]) % i] + f[j][k][l]) % p;
				}
			}
		}
		z = (z + f[n][i][0]) % p;
	}
	cout << z << endl;
	return 0;
}
