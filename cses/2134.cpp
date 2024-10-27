#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[200020];
int b[200020];
int f[200020];
int l[200020];
int s[200020];
int L[200020];
int R[200020];
int w[200020];
int d[200020];
int ss;
int mx[800020];
void build(int x, int l, int r)
{
	if (l + 1 == r)
	{
		mx[x] = w[s[l]];
		return;
	}
	int mid = (l + r) / 2;
	build(x * 2, l, mid);
	build(x * 2 + 1, mid, r);
	mx[x] = max(mx[x * 2], mx[x * 2 + 1]);
}
void change(int x, int l, int r, int p)
{
	if (l + 1 == r)
	{
		mx[x] = w[s[l]];
		return;
	}
	int mid = (l + r) / 2;
	if (p < mid)
	{
		change(x * 2, l, mid, p);
	}
	else
	{
		change(x * 2 + 1, mid, r, p);
	}
	mx[x] = max(mx[x * 2], mx[x * 2 + 1]);
}
int querycnt = 0;
int query(int x, int l, int r, int L, int R)
{
	if (x == 1) querycnt++;
	if (r <= L || R <= l)
	{
		return 0;
	}
	if (L <= l && r <= R)
	{
		return mx[x];
	}
	int mid = (l + r) / 2;
	return max(query(x * 2, l, mid, L, R),  query(x * 2 + 1, mid, r, L, R));
}
void dfs(int x, int y)
{
	s[x] = 1;
	f[x] = y;
	d[x] = d[y] + 1;
	for (int i : a[x])
	{
		if (i != y)
		{
			dfs(i, x);
			s[x] += s[i];
			if (!b[x] || s[b[x]] < s[i])
			{
				b[x] = i;
			}
		}
	}
}
void dfs2(int x, int y)
{
	l[x] = y;
	s[ss] = x;
	L[x] = ss++;
	if (b[x] > 0)
	{
		dfs2(b[x], y);
	}
	for (int i : a[x])
	{
		if (i != b[x] && i != f[x])
		{
			dfs2(i, i);
		}
	}
	R[x] = ss;
}
int askcnt = 0;
int ask(int x, int y)
{
	askcnt++;
	int re = 0;
	for (; l[x] != l[y]; x = f[l[x]])
	{
		if (d[l[x]] < d[l[y]])
		{
			swap(x, y);
		}
		if (l[x] == x)
		{
			re = max(re, w[x]);
		}
		else
		{
			re = max(re, query(1, 0, n, L[l[x]], L[x] + 1));
		}
	}
	if (L[x] > L[y])
	{
		swap(x, y);
	}
	re = max(re, query(1, 0, n, L[x], L[y] + 1));
	return re;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &w[i]);
	}
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	dfs2(1, 1);
	build(1, 0, n);
	for (int i = 0; i < m; i++)
	{
		int o, x, y;
		scanf("%d%d%d", &o, &x, &y);
		if (o == 1)
		{
			w[x] = y;
			change(1, 0, n, L[x]);
		}
		else if (o == 2)
		{
			printf("%d ", ask(x, y));
		}
	}
	// cerr << askcnt << endl;
	// cerr << querycnt << endl;
	return 0;
}