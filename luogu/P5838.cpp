#include <bits/stdc++.h>
using namespace std;
int n, m;
int cl[100020];
vector<int> cc[100020];
vector<int> a[100020];
int f[100020][20];
int c[100020];
int d[100020];
int L[100020];
int R[100020];
int s[100020], ss;
char z[100020];
vector<pair<pair<int, int>, int> > q[100020];
void change(int x, int y)
{
	for (; x <= n; x += x & -x)
	{
		c[x] += y;
	}
}
int query(int x)
{
	int re = 0;
	for (; x > 0; x -= x & -x)
	{
		re += c[x];
	}
	return re;
}
void dfs(int x, int y)
{
	L[x] = ss;
	s[ss++] = x;
	f[x][0] = y;
	d[x] = d[y] + 1;
	for (int i = 1; i < 20; i++)
	{
		f[x][i] = f[f[x][i - 1]][i - 1];
	}
	for (int i : a[x])
	{
		if (i != y)
		{
			dfs(i, x);
		}
	}
	R[x] = ss;
}
int lca(int x, int y)
{
	if (d[x] < d[y])
	{
		swap(x, y);
	}
	int dd = d[x] - d[y];
	for (int i = 0; i < 20; i++)
	{
		if (dd >> i & 1)
		{
			x = f[x][i];
		}
	}
	if (x == y)
	{
		return x;
	}
	for (int i = 20 - 1; i >= 0; i--)
	{
		if (f[x][i] != f[y][i])
		{
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}
int main()
{
	ss = 1;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &cl[i]);
		cc[cl[i]].push_back(i);
	}
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	for (int i = 0; i < m; i++)
	{
		int x, y, o;
		scanf("%d%d%d", &x, &y, &o);
		q[o].push_back(make_pair(make_pair(x, y), i));
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < cc[i].size(); j++)
		{
			change(L[cc[i][j]], 1);
			change(R[cc[i][j]], -1);
		}
		for (int j = 0; j < q[i].size(); j++)
		{
			int x = q[i][j].first.first;
			int y = q[i][j].first.second;
			int l = lca(x, y);
			int cnt = query(L[x]) + query(L[y]) - 2 * query(L[l]) + (cl[l] == i);
			z[q[i][j].second] = (cnt > 0) + '0';
		}
		for (int j = 0; j < cc[i].size(); j++)
		{
			change(L[cc[i][j]], -1);
			change(R[cc[i][j]], 1);
		}
	}
	printf("%s\n", z);
	return 0;
}