#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[200020];
long long s[800020];
long long ad[800020];
long long df[800020];
void build(int x, int l, int r)
{
	if (l == r)
	{
		s[x] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(x * 2, l, mid);
	build(x * 2 + 1, mid + 1, r);
	s[x] = s[x * 2] + s[x * 2 + 1];
}
void zuo(int x, int l, int r, long long add, long long dif)
{
	s[x] += (add + l * dif + add + r * dif) * (r - l + 1) / 2;
	ad[x] += add;
	df[x] += dif;
}
void push(int x, int l, int r)
{
	int mid = (l + r) / 2;
	zuo(x * 2, l, mid, ad[x], df[x]);
	zuo(x * 2 + 1, mid + 1, r, ad[x], df[x]);
	ad[x] = 0;
	df[x] = 0;
}
void change(int x, int l, int r, int L, int R, long long add, long long dif)
{
	if (r < L || R < l)
	{
		return;
	}
	if (L <= l && r <= R)
	{
		zuo(x, l, r, add, dif);
		return;
	}
	push(x, l, r);
	int mid = (l + r) / 2;
	change(x * 2, l, mid, L, R, add, dif);
	change(x * 2 + 1, mid + 1, r, L, R, add, dif);
	s[x] = s[x * 2] + s[x * 2 + 1];
}
long long query(int x, int l, int r, int L, int R)
{
	if (r < L || R < l)
	{
		return 0;
	}
	if (L <= l && r <= R)
	{
		return s[x];
	}
	push(x, l, r);
	int mid = (l + r) / 2;
	return query(x * 2, l, mid, L, R) + query(x * 2 + 1, mid + 1, r, L, R);
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	build(1, 1, n);
	for (int i = 0; i < m; i++)
	{
		int o, x, y;
		long long add, dif;
		scanf("%d%d%d", &o, &x, &y);
		if (o == 1)
		{
			change(1, 1, n, x, y, -x + 1, 1);
		}
		else
		{
			printf("%lld\n", query(1, 1, n, x, y));
		}
	}
	return 0;
}