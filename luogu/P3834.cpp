#include <bits/stdc++.h>
using namespace std;
struct
{
	int lc, rc, sm;
} t[4000020];
int n, m, tt;
int a[200020];
int b[200020], bc;
int r[200020];
int change(int x, int l, int r, int p)
{
	int u = ++tt;
	t[u] = t[x];
	t[u].sm++;
	if (l < r)
	{
		int mid = (l + r) / 2;
		if (p > mid)
		{
			t[u].rc = change(t[x].rc, mid+1, r, p);
		}
		else
		{
			t[u].lc = change(t[x].lc, l, mid, p);
		}
	}
	return u;
}
int query(int x, int y, int l, int r, int s)
{
	if (l == r)
	{
		return l;
	}
	int mid = (l + r) / 2;
	int d = t[t[y].lc].sm - t[t[x].lc].sm;
	if (d < s)
	{
		return query(t[x].rc, t[y].rc, mid+1, r, s - d);
	}
	else
	{
		return query(t[x].lc, t[y].lc, l, mid, s);
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		b[bc++] = a[i];
	}
	sort(b, b + bc);
	bc = unique(b, b + bc) - b;
	r[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		a[i] = lower_bound(b, b + bc, a[i]) - b;
		r[i] = change(r[i - 1], 0, bc - 1, a[i]);
	}
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		printf("%d\n", b[query(r[x - 1], r[y], 0, bc - 1, z)]);
	}
	return 0;
}