#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200020];
int mn[800020];
void build(int x, int l, int r)
{
	if (l == r)
	{
		mn[x] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(x * 2, l, mid);
	build(x * 2 + 1, mid + 1, r);
	mn[x] = min(mn[x * 2], mn[x * 2 + 1]);
}
void change(int x, int l, int r, int p, int v)
{
	if (l == r)
	{
		mn[x] = v;
		return;
	}
	int mid = (l + r) / 2;
	if (p > mid)
	{
		change(x * 2 + 1, mid + 1, r, p, v);
	}
	else
	{
		change(x * 2, l, mid, p, v);
	}
	mn[x] = min(mn[x * 2], mn[x * 2 + 1]);
}
int query(int x, int l, int r, int L, int R)
{
	if (r < L || R < l)
	{
		return 1e9;
	}
	if (L <= l && r <= R)
	{
		return mn[x];
	}
	int mid = (l + r) / 2;
	return min(query(x * 2, l, mid, L, R), query(x * 2 + 1, mid + 1, r, L, R));
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	build(1, 1, n);
	for (int i = 0; i < m; i++)
	{
		int o, x, y;
		scanf("%d%d%d", &o, &x, &y);
		if (o == 2)
		{
			printf("%d\n", query(1, 1, n, x, y));
		}
		else
		{
			change(1, 1, n, x, y);
		}
	}
	return 0;
}