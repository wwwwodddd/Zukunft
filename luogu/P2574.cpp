#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[800020];
int v[800020];
void build(int x, int l, int r)
{
	if (l == r)
	{
		scanf("%1d", &a[x]);
		return;
	}
	int mid = (l + r) / 2;
	build(x * 2, l, mid);
	build(x * 2 + 1, mid + 1, r);
	a[x] = a[x * 2] + a[x * 2 + 1];
}
void change(int x, int l, int r, int L, int R)
{
	if (r < L || R < l)
	{
		return;
	}
	if (L <= l && r <= R)
	{
		v[x] ^= 1;
		a[x] = r - l + 1 - a[x];
		return;
	}
	int mid = (l + r) / 2;
	change(x * 2, l, mid, L, R);
	change(x * 2 + 1, mid + 1, r, L, R);
	a[x] = a[x * 2] + a[x * 2 + 1];
	if (v[x])
	{
		a[x] = r - l + 1 - a[x];
	}
}
int query(int x, int l, int r, int L, int R)
{
	if (r < L || R < l)
	{
		return 0;
	}
	if (L <= l && r <= R)
	{
		return a[x];
	}
	int mid = (l + r) / 2;
	int re = query(x * 2, l, mid, L, R) + query(x * 2 + 1, mid + 1, r, L, R);
	if (v[x])
	{
		re = min(r, R) - max(l, L) + 1 - re;
	}
	return re;
}
int main()
{
	scanf("%d%d", &n, &m);
	build(1, 1, n);
	for (int i = 0; i < m; i++)
	{
		int o, x, y;
		scanf("%d%d%d", &o, &x, &y);
		if (o)
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