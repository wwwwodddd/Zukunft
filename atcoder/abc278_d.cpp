#include <bits/stdc++.h>
using namespace std;
int n, m, p;
long long s[800020];
long long b[800020];
void build(int x, int l, int r)
{
	b[x] = -1;
	if (l == r)
	{
		scanf("%lld", &s[x]);
		return;
	}
	int mid = (l + r) / 2;
	build(x * 2, l, mid);
	build(x * 2 + 1, mid + 1, r);
}
void sam(int x, int y)
{
	s[x] = y;
	b[x] = y;
}
void push(int x)
{
	if (b[x] != -1)
	{
		sam(x * 2, b[x]);
		sam(x * 2 + 1, b[x]);
	}
	b[x] = -1;
}
void change(int x, int l, int r, int L, int R, int v)
{
	if(r < L || R < l)
	{
		return;
	}
	if (L <= l && r <= R)
	{
		sam(x, v);
		return;
	}
	push(x);
	int mid = (l + r) / 2;
	change(x * 2, l, mid, L, R, v);
	change(x * 2 + 1, mid + 1, r, L, R, v);
	return;
}
void modify(int x, int l, int r, int p, int v)
{
	if (l == r)
	{
		s[x] += v;
		return;
	}
	push(x);
	int mid = (l + r) / 2;
	if (p <= mid)
	{
		modify(x * 2, l, mid, p, v);
	}
	else
	{
		modify(x * 2 + 1, mid + 1, r, p, v);
	}
	return;
}
long long query(int x, int l, int r, int p)
{
	if (l == r)
	{
		return s[x];
	}
	push(x);
	int mid = (l + r) / 2;
	if (p <= mid)
	{
		return query(x * 2, l, mid, p);
	}
	else
	{
		return query(x * 2 + 1, mid + 1, r, p);
	}
}
int main()
{
	scanf("%d", &n);
	build(1, 1, n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int o, x, y;
		scanf("%d", &o);
		if (o == 1)
		{
			scanf("%d", &x);
			change(1, 1, n, 1, n, x);
		}
		else if (o == 2)
		{
			scanf("%d%d", &x, &y);
			modify(1, 1, n, x, y);
		}
		else
		{
			scanf("%d", &x);
			printf("%lld\n", query(1, 1, n, x));
		}
	}
	return 0;
}
