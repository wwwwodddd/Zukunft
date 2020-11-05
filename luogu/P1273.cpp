#include <bits/stdc++.h>
using namespace std;
int f[3020][3020];
vector<int> a[3020];
int v[3020];
int w[3020];
int n, m, l, x, y;
int dfs(int x)
{
	f[x][0] = 0;
	if (x > n - m)
	{
		f[x][1] = v[x];
		return 1;
	}
	int s = 0;
	for (int i: a[x])
	{
		int t = dfs(i);
		for (int j = s; j >= 0; j--)
		{
			for (int k = t; k > 0; k--)
			{
				f[x][j + k] = max(f[x][j + k], f[x][j] + w[i] + f[i][k]);
			}
		}
		s += t;
	}
	return s;
}
int main()
{
	scanf("%d%d", &n, &m);
	memset(f, 0xc0, sizeof f);
	for (int i = 1; i <= n - m; i++)
	{
		scanf("%d", &l);
		for (int j = 0; j < l; j++)
		{
			scanf("%d%d", &x, &y);
			a[i].push_back(x);
			w[x] = -y;
		}
	}
	for (int i = n - m + 1; i <= n; i++)
	{
		scanf("%d", &v[i]);
	}
	dfs(1);
	for (int i = m; i > 0; i--)
	{
		if (f[1][i] >= 0)
		{
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}