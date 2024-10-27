#include <bits/stdc++.h>
using namespace std;
int n, m;
struct Node
{
	long long sm, lm, rm, mx;
	Node(long long sm = 0, long long lm = 0, long long rm = 0, long long mx = 0) : sm(sm), lm(lm), rm(rm), mx(mx)
	{
	}
} t[1048577];
int a[500020];
Node operator+(const Node &a, const Node &b)
{
	return Node(a.sm + b.sm, max(a.lm, a.sm + b.lm), max(a.rm + b.sm, b.rm), max(a.rm + b.lm, max(a.mx, b.mx)));
}
void build(int x, int l, int r)
{
	if (l == r)
	{
		t[x] = Node(a[l], a[l], a[l], a[l]);
		return;
	}
	int mid = (l + r) / 2;
	build(x * 2, l, mid);
	build(x * 2 + 1, mid + 1, r);
	t[x] = t[x * 2] + t[x * 2 + 1];
}
void change(int x, int l, int r, int p, int v)
{
	if (l == r)
	{
		t[x] = Node(v, v, v, v);
		return;
	}
	int mid = (l + r) / 2;
	if (p > mid)
	{
		change(2 * x + 1, mid + 1, r, p, v);
	}
	else
	{
		change(2 * x, l, mid, p, v);
	}
	t[x] = t[x * 2] + t[x * 2 + 1];
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
		int x, y;
		scanf("%d%d", &x, &y);
		change(1, 1, n, x, y);
		printf("%lld\n", max(t[1].mx, 0LL));
	}
	return 0;
}