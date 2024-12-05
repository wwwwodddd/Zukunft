#include <bits/stdc++.h>
using namespace std;
int n, m;
int f[320][320];
vector<int> a[320];
int dfs(int x, int y)
{
	int s = 1;
	for (int i: a[x])
	{
		if (i != y)
		{
			int t = dfs(i, x);
			for (int j = s; j >= 1; j--)
			{
				for (int k = 0; k <= t; k++)
				{
					f[x][j + k] = max(f[x][j + k], f[x][j] + f[i][k]);
				}
			}
			s += t;
		}
	}
	return s;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x >> f[i][1];
		a[x].push_back(i);
	}
	dfs(0, -1);
	cout << f[0][m + 1] << endl;
	return 0;
}