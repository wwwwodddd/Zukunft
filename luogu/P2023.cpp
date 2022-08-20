#include <bits/stdc++.h>
using namespace std;
int n, m, p;
long long s[400020];
long long a[400020];
long long t[400020];
void build(int x, int l, int r)
{
	t[x] = 1;
	if (l == r)
	{
		scanf("%lld", &s[x]);
		return;
	}
	int mid = (l + r) / 2;
	build(x * 2, l, mid);
	build(x * 2 + 1, mid + 1, r);
	s[x] = (s[x * 2] + s[x * 2 + 1]) % p;
}
void mul(int x,int y)
{
	s[x] = s[x] * y % p;
	a[x] = a[x] * y % p;
	t[x] = t[x] * y % p;
}
void add(int x, int l, int r, int y)
{
	a[x] = (a[x] + y) % p;
	s[x] = (s[x] + y * (r - l + 1LL)) % p;
}
void push(int x, int l, int r)
{
	int mid = (l + r) / 2;
	mul(x * 2, t[x]);
	mul(x * 2 + 1, t[x]);
	add(x * 2, l, mid, a[x]);
	add(x * 2 + 1, mid + 1, r, a[x]);
	t[x] = 1;
	a[x] = 0;
}
void change(int x, int l, int r, int L, int R, int T, int A)
{
	if(r < L || R < l)
	{
		return;
	}
	if (L <= l && r <= R)
	{
		mul(x, T);
		add(x, l, r, A);
		return;
	}
	push(x, l, r);
	int mid = (l + r) / 2;
	change(x * 2, l, mid, L, R, T, A);
	change(x * 2 + 1, mid + 1, r, L, R, T, A);
	s[x] = (s[x * 2] + s[x * 2 + 1]) % p;
	return;
}
int query(int x, int l, int r, int L, int R)
{
	if(r < L || R < l)
	{
		return 0;
	}
	if (L <= l && r <= R)
	{
		return s[x];
	}
	push(x, l, r);
	int mid = (l + r) / 2;
	return (query(x * 2, l, mid, L, R) + query(x * 2 + 1, mid + 1, r, L, R)) % p;
}
int main()
{
	scanf("%d%d", &n, &p);
	build(1, 1, n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int o, x, y, z;
		scanf("%d", &o);
		if (o == 1)
		{
			scanf("%d%d%d", &x, &y, &z);
			change(1, 1, n, x, y, z, 0);
		}
		else if (o == 2)
		{
			scanf("%d%d%d", &x, &y, &z);
			change(1, 1, n, x, y, 1, z);
		}
		else
		{
			scanf("%d%d", &x, &y);
			printf("%d\n", query(1, 1, n, x, y));
		}
	}
	return 0;
}
