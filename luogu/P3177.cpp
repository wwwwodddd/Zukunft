#include <bits/stdc++.h>
using namespace std;
long long f[2020][2020];
int n, m, x, y, z;
vector<pair<int, int> > a[2020];
int dfs(int x, int y)
{
	f[x][0] = 0;
	f[x][1] = 0;
	int s = 1;
	for (pair<int, int> i: a[x])
	{
		if (i.first != y)
		{
			int r = dfs(i.first, x);
			for (int j = min(m, s); j >= 0; j--)
			{
				for (int k = min(m - j, r); k >= 0; k--)
				{
					f[x][j + k] = max(f[x][j + k], f[x][j] + f[i.first][k] + (long long)i.second * (k * (m - k) + (r - k) * (n - m - r + k)));
				}
			}
			s += r;
		}
	}
	return s;
}
int main()
{
	memset(f, 0xc0, sizeof f);
	cin >> n >> m;
	for (int i = 1; i < n; i++)
	{
		cin >> x >> y >> z;
		a[x].push_back(make_pair(y, z));
		a[y].push_back(make_pair(x, z));
	}
	dfs(1, 0);
	cout << f[1][m] << endl;
	return 0;
}