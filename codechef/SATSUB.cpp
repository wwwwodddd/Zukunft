#include <bits/stdc++.h>
using namespace std;
int n, m;
struct Node
{
	int sm, lm, rm, mx, lc, rc;
	long long sc;
	Node(int sm = 0, int lm = 0, int rm = 0, int mx = 0, int lc = 0, int rc = 0, long long sc = 0) : sm(sm), lm(lm), rm(rm), mx(mx), lc(lc), rc(rc), sc(sc)
	{
	}
} t[1048577];
int a[500020];
Node operator+(const Node &a, const Node &b)
{
	return Node(a.sm + b.sm, max(a.lm, a.sm + b.lm), max(a.rm + b.sm, b.rm), max(a.rm + b.lm, max(a.mx, b.mx)), (a.sm < 0 ? a.lc : (a.lc + b.lc)), (b.sm < 0 ? b.rc : (a.rc + b.rc)), a.sc + b.sc + (long long)a.rc * b.lc);
}
void build(int x, int l, int r)
{
	if (l == r)
	{
		if (a[l] < 0)
		{
			t[x] = Node(a[l], 0, 0, 0, 0, 0, 0);
		}
		else
		{
			t[x] = Node(a[l], a[l], a[l], a[l], 1, 1, 1);
		}
		return;
	}
	int mid = (l + r) / 2;
	build(x * 2, l, mid);
	build(x * 2 + 1, mid + 1, r);
	t[x] = t[x * 2] + t[x * 2 + 1];
}
Node query(int x, int l, int r, int L, int R)
{
	if (L <= l && r <= R)
	{
		return t[x];
	}
	int mid = (l + r) / 2;
	if (R <= mid)
	{
		return query(x * 2, l, mid, L, R);
	}
	if (L > mid)
	{
		return query(x * 2 + 1, mid + 1, r, L, R);
	}
	return query(x * 2, l, mid, L, R) + query(x * 2 + 1, mid + 1, r, L, R);
}
int main()
{
	int t;
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		build(1, 1, n);
		for (int i = 0; i < m; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			printf("%lld\n", query(1, 1, n, x, y).sc);
		}
	}
	return 0;
}