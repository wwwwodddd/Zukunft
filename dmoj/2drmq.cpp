#include <bits/stdc++.h>
using namespace std;
int f[11][11][1001][1001];
int lg(int x)
{
	return 31 - __builtin_clz(x);
}
void init(vector<vector<int> > a)
{
	int n = a.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			f[0][0][i][j] = a[i][j];
		}
	}
	for (int k = 0; 1 << k <= n; k++)
	{
		for (int l = 0; 1 << l <= n; l++)
		{
			if (k + l)
			{
				for (int i = 0; i + (1 << k) <= n; i++)
				{
					for (int j = 0; j + (1 << l) <= n; j++)
					{
						if (k)
						{
							f[k][l][i][j] = min(f[k - 1][l][i][j], f[k - 1][l][i + (1 << (k - 1))][j]);
						}
						else
						{
							f[k][l][i][j] = min(f[k][l - 1][i][j], f[k][l - 1][i][j + (1 << (l - 1))]);
						}
					}
				}
			}
		}
	}
}
int query(int x1, int x2, int y1, int y2)
{
	int dx = lg(x2 - x1 + 1), dy = lg(y2 - y1 + 1);
	return min(min(f[dx][dy][x1][y1], f[dx][dy][x2 - (1 << dx) + 1][y1]), min(f[dx][dy][x1][y2 - (1 << dy) + 1], f[dx][dy][x2 - (1 << dx) + 1][y2 - (1 << dy) + 1]));
}
