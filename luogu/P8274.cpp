#include <bits/stdc++.h>
using namespace std;
int t;
vector<int> a[100020];
int l[100020];
int r[100020];
int f[100020];
int g[100020];
int z[100020];
int n, b, M, v;
void dfs(int x)
{
	f[x] = 0;
	g[x] = 1e9;
	for (int i : a[x])
	{
		dfs(i);
		f[x] = max(f[x], f[i]);
		g[x] = min(g[x], g[i]);
	}
	if (max(f[x], l[x]) <= min(g[x], r[x]))
	{
		f[x] = max(f[x], l[x]);
		g[x] = min(g[x], r[x]);
	}
	else if (max(l[x], f[x] - M) > min(r[x], g[x] + M))
	{
		v = 1; // no solution
	}
	else
	{
		f[x] = max(f[x], l[x]);
		g[x] = min(g[x], r[x]);
	}
}
void gen(int x, int y)
{
	if (f[x] <= g[x])
	{
		z[x] = max(f[x], y - M);
	}
	else
	{
		z[x] = max(max(f[x], y) - M, l[x]);
	}
	for (int i : a[x])
	{
		gen(i, max(y, z[x]));
	}
}
int main()
{
	cin >> t >> b;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			a[i].clear();
		}
		for (int i = 2; i <= n; i++)
		{
			cin >> v;
			a[v].push_back(i);
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> l[i] >> r[i];
		}
		int L = -1;
		int R = 1e9 + 7;
		while (L < R - 1)
		{
			M = (L + R) / 2;
			v = 0;
			dfs(1);
			if (v)
			{
				L = M;
			}
			else
			{
				R = M;
			}
		}
		cout << R << endl;
		if (b)
		{
			M = R;
			v = 0;
			dfs(1);
			gen(1, 0);
			for (int i = 1; i < n; i++)
			{
				cout << z[i] << " ";
			}
			cout << z[n] << endl;
		}
	}
	return 0;
}