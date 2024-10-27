#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200020];
int mnl[800020];
int mnr[800020];
void build(int x, int l, int r)
{
	if (l == r)
	{
		mnl[x] = a[l] - l;
		mnr[x] = a[l] + r;
		return;
	}
	int mid = (l + r) / 2;
	build(x * 2, l, mid);
	build(x * 2 + 1, mid + 1, r);
	mnl[x] = min(mnl[x * 2], mnl[x * 2 + 1]);
	mnr[x] = min(mnr[x * 2], mnr[x * 2 + 1]);
}
void change(int x, int l, int r, int p, int v)
{
	if (l == r)
	{
		mnl[x] = v - l;
		mnr[x] = v + r;
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
	mnl[x] = min(mnl[x * 2], mnl[x * 2 + 1]);
	mnr[x] = min(mnr[x * 2], mnr[x * 2 + 1]);
}
int query(int x, int l, int r, int L, int R, int* mn)
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
	return min(query(x * 2, l, mid, L, R, mn), query(x * 2 + 1, mid + 1, r, L, R, mn));
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
		scanf("%d%d", &o, &x);
		if (o == 2)
		{
			printf("%d\n", min(query(1, 1, n, 1, x, mnl) + x, query(1, 1, n, x, n, mnr) - x));
		}
		else
		{
			scanf("%d", &y);
			change(1, 1, n, x, y);
		}
	}
	return 0;
}