#include <bits/stdc++.h>
using namespace std;
int f[501][501], n, m;
int main()
{
	memset(f, 0x3f, sizeof f);
	cin >> n >> m;
	for (int i = 0; i < 501; i++)
	{
		f[i][i] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int k = 1; k < i; k++)
			{
				f[i][j] = min(f[i][j], f[k][j] + f[i - k][j] + 1);
			}
			for (int k = 1; k < j; k++)
			{
				f[i][j] = min(f[i][j], f[i][k] + f[i][j - k] + 1);
			}
		}
	}
	cout << f[n][m] << endl;
	return 0;
}