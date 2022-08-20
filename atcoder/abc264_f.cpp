#include <bits/stdc++.h>
using namespace std;
int n, m;
int r[2020];
int c[2020];
int a[2020][2020];
long long f[2020][2020][2][2];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &r[i]);
	}
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &c[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%1d", &a[i][j]);
		}
	}
	memset(f, 0x3f, sizeof f);
	f[1][1][0][0] = 0;
	f[1][1][1][0] = r[1];
	f[1][1][0][1] = c[1];
	f[1][1][1][1] = r[1] + c[1];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				for (int l = 0; l < 2; l++)
				{
					if (i < n)
					{
						int nk = a[i][j] ^ k ^ a[i + 1][j];
						f[i + 1][j][nk][l] = min(f[i + 1][j][nk][l], f[i][j][k][l] + nk * r[i + 1]);
					}
					if (j < m)
					{
						int nl = a[i][j] ^ l ^ a[i][j + 1];
						f[i][j + 1][k][nl] = min(f[i][j + 1][k][nl], f[i][j][k][l] + nl * c[j + 1]);
					}
				}
			}
		}
	}
	cout << min(min(f[n][m][0][0], f[n][m][0][1]), min(f[n][m][1][0], f[n][m][1][1])) << endl;
	return 0;
}
