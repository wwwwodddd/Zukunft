#include <bits/stdc++.h>
using namespace std;
int n, m, d;
int a[120];
long long f[120][120][120];
int main()
{
	cin >> n >> m >> d;
	memset(f, -1, sizeof f);
	f[0][0][0] = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		for (int j = 0; j <= i; j++)
		{
			for (int k = 0; k < d; k++)
			{
				if (f[i][j][k] != -1)
				{
					f[i + 1][j][k] = max(f[i + 1][j][k], f[i][j][k]);
					f[i + 1][j + 1][(k + a[i]) % d] = max(f[i + 1][j + 1][(k + a[i]) % d], f[i][j][k] + a[i]);
				}
			}
		}
	}
	cout << f[n][m][0] << endl;
	return 0;
}
