#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z;
int a[21][21];
vector<pair<int, int> > b[21];
int f[1048577];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		b[x].push_back(make_pair(y, z));
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 0; i <= n; i++)
	{
		sort(b[x].begin(), b[x].end());
	}
	for (int i = 0; i < 1 << n; i++)
	{
		int k = __builtin_popcount(i);
		for (int j = 0; j < n; j++)
		{
			if (i >> j & 1)
			{
				f[i] = max(f[i], f[i ^ 1 << j] + a[j][k]);
			}
		}
		for (pair<int, int> j: b[k])
		{
			if (f[i] >= j.first)
			{
				f[i] += j.second;
			}
		}
	}
	printf("%d\n", f[(1 << n) - 1]);
	return 0;
}