#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int n, m;
vector<int> a[1020];
int s[1020];
int f[1020][5020][7];
void inc(int &x, long long y)
{
	x = (x + y) % p;
}
void dfs(int x, int y)
{
	s[x] = 1;
	for (int i = 1; i <= m; i++)
	{
		f[x][0][i] = 1;
	}
	for (int c : a[x])
	{
		if (c != y)
		{
			dfs(c, x);
			int g[5020][7] = {};
			for (int xi = 0; xi <= s[x] * m; xi++)
			{
				for (int xj = 0; xj <= m; xj++)
				{
					if (f[x][xi][xj] == 0)
					{
						continue;
					}
					for (int ci = 0; ci <= s[c] * m; ci++)
					{
						for (int cj = 0; cj <= m; cj++)
						{
							if (f[c][ci][cj] == 0)
							{
								continue;
							}
							inc(g[xi + ci + cj][max(xj - cj, 0)], (long long)f[x][xi][xj] * f[c][ci][cj]);
						}
					}
				}
			}
			swap(f[x], g);
			s[x] += s[c];
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	for (int i = 1; i <= n * m; i++)
	{
		int z = 0;
		for (int j = 0; j <= m && j <= i; j++)
		{
			inc(z, f[1][i - j][j]);
		}
		cout << z << endl;
	}
	return 0;
}