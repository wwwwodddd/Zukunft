#include <bits/stdc++.h>
using namespace std;
int n, q;
vector<pair<int, int> > a[300020];
int b[300020];
int d[300020];
int f[300020];
int g[300020];
int v[300020];
int w[500020];
int x[500020];
int y[500020];
int z[500020];
int l[600020];
int s[600020];
int L[600020];
int R[600020];
int ss;
int sm[600020];
int ad[600020];
void add(int x, int l, int r, int v)
{
	sm[x] = (r - l) * v;
	ad[x] += v;
}
void push(int x, int l, int r)
{
	if (ad[x])
	{
		int mid = (l + r) / 2;
		add(x * 2, l, mid, ad[x]);
		add(x * 2 + 1, mid, r, ad[x]);
		ad[x] = 0;
	}
}
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
bool U(int x, int y)
{
	x = F(x);
	y = F(y);
	if (x == y)
	{
		return false;
	}
	else
	{
		f[x] = y;
		return true;
	}
}
void dfs(int x, int y)
{
	d[x] = d[y] + 1;
	f[x] = y;
	s[x] = 1;
	for (pair<int, int> i : a[x])
	{
		if (i.first != y)
		{
			g[i.first] = g[x] ^ i.second;
			dfs(i.first, x);
			s[x] += s[i.first];
			if (!b[x] || s[b[x]] < s[i.first])
			{
				b[x] = i.first;
			}
		}
	}
}
void dfs2(int x, int y)
{
	l[x] = y;
	L[x] = ss++;
	if (b[x] > 0)
	{
		dfs2(b[x], y);
	}
	for (pair<int, int> i : a[x])
	{
		if (i.first != f[x] && i.first != b[x])
		{
			dfs2(i.first, i.first);
		}
	}
	R[x] = ss;
}
void change(int x, int l, int r, int L, int R, int v)
{
	if (r <= L || R <= l)
	{
		return;
	}
	if (L <= l && r <= R)
	{
		add(x, l, r, v);
		return;
	}
	push(x, l, r);
	int mid = (l + r) / 2;
	change(x * 2, l, mid, L, R, v);
	change(x * 2 + 1, mid, r, L, R, v);
	sm[x] = sm[x * 2] + sm[x * 2 + 1];
}
int query(int x, int l, int r, int L, int R)
{
	if (r <= L || R <= l)
	{
		return 0;
	}
	if (L <= l && r <= R)
	{
		return sm[x];
	}
	push(x, l, r);
	int mid = (l + r) / 2;
	return query(x * 2, l, mid, L, R) + query(x * 2 + 1, mid, r, L, R);
}
void changepath(int x, int y)
{
	for (; l[x] != l[y]; x = f[l[x]])
	{
		if (d[l[x]] < d[l[y]])
		{
			swap(x, y);
		}
		change(1, 0, n, L[l[x]], L[x] + 1, 1);
	}
	if (L[x] > L[y])
	{
		swap(x, y);
	}
	change(1, 0, n, L[x] + 1, L[y] + 1, 1);
}
int querypath(int x, int y)
{
	int re = 0;
	for (; l[x] != l[y]; x = f[l[x]])
	{
		if (d[l[x]] < d[l[y]])
		{
			swap(x, y);
		}
		re += query(1, 0, n, L[l[x]], L[x] + 1);
	}
	if (L[x] > L[y])
	{
		swap(x, y);
	}
	re += query(1, 0, n, L[x] + 1, L[y] + 1);
	return re;
}
int main()
{
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
	}
	for (int i = 0; i < q; i++)
	{
		cin >> x[i] >> y[i] >> w[i];
		if (U(x[i], y[i]))
		{
			a[x[i]].push_back(make_pair(y[i], w[i]));
			a[y[i]].push_back(make_pair(x[i], w[i]));
			z[i] = 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (d[i] == 0)
		{
			dfs(i, 0);
			dfs2(i, i);
		}
	}
	for (int i = 0; i < q; i++)
	{
		if (!z[i] && (g[x[i]] ^ g[y[i]]) != w[i])
		{
			if (querypath(x[i], y[i]) == 0)
			{
				changepath(x[i], y[i]);
				z[i] = 1;
			}
		}
	}
	for (int i = 0; i < q; i++)
	{
		puts(z[i] ? "YES" : "NO");
	}
	return 0;
}