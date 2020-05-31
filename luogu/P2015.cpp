#include <bits/stdc++.h>
using namespace std;
int n, m, f[120][120];
vector<pair<int, int> > a[120];
int dfs(int x, int y)
{
	int s = 0;
	for (pair<int, int> i: a[x])
	{
		if (i.first != y)
		{
			int t = dfs(i.first, x);
			for (int j = s; j >= 0; j--)
			{
				for (int k = 0; k <= t; k++)
				{
					f[x][j + k + 1] = max(f[x][j + k + 1], f[x][j] + f[i.first][k] + i.second);
				}
			}
			s += t + 1;
		}
	}
	return s;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i < n; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		a[x].push_back(make_pair(y, z));
		a[y].push_back(make_pair(x, z));
	}
	dfs(1, 0);
	cout << f[1][m] << endl;
	return 0;
}