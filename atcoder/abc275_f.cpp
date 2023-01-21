#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[3020];
int f[3020][3020][2];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	memset(f, 0x3f, sizeof f);
	f[0][0][0] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (j + a[i] <= m)
			{
				f[i + 1][j + a[i]][0] = min(f[i + 1][j + a[i]][0], min(f[i][j][0], f[i][j][1]));
			}
			f[i + 1][j][1] = min(f[i + 1][j][1], min(f[i][j][0] + 1, f[i][j][1]));
		}
	}
	for (int i = 1; i <= m; i++)
	{
		int z = min(f[n][i][0], f[n][i][1]);
		if (z > n)
		{
			z = -1;
		}
		cout << z << endl;
	}
	return 0;
}