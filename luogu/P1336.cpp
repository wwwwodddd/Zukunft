#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
long long f[22][222];
int main()
{
	cin >> n >> m;
	memset(f, 0x3f, sizeof f);
	f[0][0] = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		for (int j = 0; j <= n; j++)
		{
			for (int k = 0; k + j <= n; k++)
			{
				f[i + 1][j + k] = min(f[i + 1][j + k], f[i][j] + (long long)(a * pow(k, b)));
			}
		}
	}
	cout << f[m][n] << endl;
	return 0;
}