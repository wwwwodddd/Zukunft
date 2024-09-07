#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1020][1020];
int f[1020][2][2];
bool ok(int i, int x, int y)
{
	for (int j = 1; j <= m; j++)
	{
		if (a[i][j] != a[i][j - 1] && a[i][j] != a[i][j + 1] && a[i][j] != (a[i - 1][j] ^ x) && a[i][j] != (a[i + 1][j] ^ y))
		{
			return false;
		}
	}
	return true;
}
int main()
{
	cin >> n >> m;
	memset(a, -1, sizeof a);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}
	}
	memset(f, 0x3f, sizeof f);
	f[1][0][0] = 0;
	f[1][0][1] = 1;
	for (int i = 2; i <= n + 1; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				for (int l = 0; l < 2; l++)
				{
					if (ok(i - 1, l ^ k, k ^ j))
					{
						f[i][k][j] = min(f[i][k][j], f[i - 1][l][k] + j);
					}
				}
			}
		}
	}
	int z = min(f[n + 1][0][0], f[n + 1][1][0]);
	if (z > n)
	{
		z = -1;
	}
	cout << z << endl;
	return 0;
}
