#include <bits/stdc++.h>
using namespace std;
int n, m, rt, mod;
vector<int> a[100020];
int b[100020];
int f[100020];
int l[100020];
int s[100020];
int L[100020];
int R[100020];
int w[100020];
int d[100020];
int ss;
long long sm[400020];
long long ad[400020];
void build(int x, int l, int r)
{
	if (l + 1 == r)
	{
		sm[x] = w[s[l]];
		return;
	}
	int mid = (l + r) / 2;
	build(x * 2, l, mid);
	build(x * 2 + 1, mid, r);
	sm[x] = (sm[x * 2] + sm[x * 2 + 1]) % mod;
}
void add(int x, int l, int r, long long v)
{
	sm[x] = (sm[x] + (r - l) * v) % mod;
	ad[x] = (ad[x] + v) % mod;
}
void push(int x, int l, int r)
{
	int mid = (l + r) / 2;
	add(x * 2, l, mid, ad[x]);
	add(x * 2 + 1, mid, r, ad[x]);
	ad[x] = 0;
}
void change(int x, int l, int r, int L, int R, long long v)
{
	if (r <= L || R <= l)
	{
		return;
	}
	if (L <= l && r <= R)
	{
		add(x, l, r, v);
		return;
	}
	push(x, l, r);
	int mid = (l + r) / 2;
	change(x * 2, l, mid, L, R, v);
	change(x * 2 + 1, mid, r, L, R, v);
	sm[x] = (sm[x * 2] + sm[x * 2 + 1]) % mod;
}
long long query(int x, int l, int r, int L, int R)
{
	if (r <= L || R <= l) {
		return 0;
	}
	if (L <= l && r <= R) {
		return sm[x];
	}
	push(x, l, r);
	int mid = (l + r) / 2;
	return (query(x * 2, l, mid, L, R) + query(x * 2 + 1, mid, r, L, R)) % mod;
}
void dfs(int x, int y)
{
	s[x] = 1;
	f[x] = y;
	d[x] = d[y] + 1;
	for (int i: a[x])
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
	for (int i: a[x])
	{
		if (i != b[x] && i != f[x])
		{
			dfs2(i, i);
		}
	}
	R[x] = ss;
}
void modify(int x, int y, long long v)
{
	for (; l[x] != l[y]; x = f[l[x]])
	{
		if (d[l[x]] < d[l[y]])
		{
			swap(x, y);
		}
		change(1, 0, n, L[l[x]], L[x] + 1, v);
	}
	if (L[x] > L[y])
	{
		swap(x, y);
	}
	change(1, 0, n, L[x], L[y] + 1, v);
}
long long ask(int x, int y)
{
	long long re = 0;
	for (; l[x] != l[y]; x = f[l[x]])
	{
		if (d[l[x]] < d[l[y]])
		{
			swap(x, y);
		}
		re = (re + query(1, 0, n, L[l[x]], L[x] + 1)) % mod;
	}
	if (L[x] > L[y])
	{
		swap(x, y);
	}
	re = (re + query(1, 0, n, L[x], L[y] + 1)) % mod;
	return re;
}
int main()
{
	scanf("%d%d%d%d", &n, &m, &rt, &mod);
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
	dfs(rt, 0);
	dfs2(rt, rt);
	build(1, 0, n);
	for (int i = 0; i < m; i++)
	{
		int o, x, y, z;
		scanf("%d%d", &o, &x);
		if (o == 1)
		{
			scanf("%d%d", &y, &z);
			modify(x, y, z);
		}
		else if (o == 2)
		{
			scanf("%d", &y);
			printf("%lld\n", ask(x, y));
		}
		else if (o == 3)
		{
			scanf("%d", &z);
			change(1, 0, n, L[x], R[x], z);
		}
		else
		{
			printf("%lld\n", query(1, 0, n, L[x], R[x]));
		}
	}
	return 0;
}